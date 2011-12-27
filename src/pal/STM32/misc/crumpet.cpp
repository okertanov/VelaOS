#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "maf.h"
#include "alias.h"
#include "token.h"
#include "probability.h"
#include <getopt.h>
#include "const.h"

#define OPT_FOOTPRINT 1001
#define OPT_INTERVAL 1002
#define OPT_COUNT 1003
#define OPT_BAYES 1004
#define OPT_SISTER1 1005
#define OPT_SISTER2 1006
#define OPT_INS 1007
#define OPT_DEL 1008



void init_interpolation();
void run_states_anc(Iterator *i);

int debug = 0;
int computelike = 1;
int conditional = 0;
int gapless = 0;
int cposition = 0;
int cachemats = 1;
int recompute = 0;
int computing = 0;
int totalcount = 0;
int printbase = 0;

int initialize;
int footprint=150;
double interval=0;
int oldmode=0;
int use_bayes=0;

int runmode = MODE_LIKELIHOOD;
extern int mfcount;
extern int m24count;
void clearhash();
void shrink_footprint();
extern Stack allnucs[];
extern Matrix<double> *m24ihash[];
double interpolate_probability(double time, Matrix<double> **input, int i, int j);


void usage()
{
	std::cerr<<"Usage:\n"
		"\tscone [options]\n"
		"\nOptions:\n"
		"\t-?, --help\t\tPrint this error message.\n"
		"\t-m, --maf <file>\t\tInput maf file.\n"
		"\t-r, --reference <species>\tName of the reference species. (default: human)\n"
		"\t-p, --sister1 <species>\tSpecies to use in defining the ancestor (default: mouse).\n"
		"\t-p, --sister2 <species>\tSecond species to use in defining the ancestor (default: the reference species)\n"
		"\t-x, --matrix <file>\tMatrix file.\n"
		"\t    --ins <file>\tInsertion vector file.\n"
		"\t    --del <file>\tDeletion vector file.\n"
		"\t-f, --freq <file>\tNucleotide frequency file.\n"
		"\t-p, --phylo <file>\t\tFile containing phylogenetic tree.\n"
		"\t-a, --alias <file>\t\tFile containing species-name aliases.\n"
		"\t-s, --scale <number>\t\tScale factor for phylogenetic tree. (length of human branch since human/chimp divergence in given units)\n"
		"\t-c, --select-position <position>\tPick a particular reference sequence position for detailed output.\n"
		"\t--debug\t\t\tDuh. Optional level argument for more goodness.\n"
		"\t--count <num>\tOnly compute <num> positions.\n";

	exit(0);
}

int main(int argc, char **argv)
{
	// load phylo
	std::string line;
	std::string aliasFile;
	std::string phyloFile;
	std::string mafFile;
	std::string insFile;
	std::string delFile;
	std::string reference="human";
	std::string sister1="mouse";
	std::string sister2;
	std::string matrixFile = HOME_DIR "m3.txt";
	std::string freqFile = HOME_DIR "f3.txt";
	double scale = 0.00331;
	
	
	
	if (argc == 1) usage();
	while (1)
	{
		static struct option long_options[] = 
		{
			{"maf", required_argument, 0, 'm'},
			{"matrix", required_argument, 0, 'x'},
			{"ins", required_argument, 0, OPT_INS},
			{"del", required_argument, 0, OPT_DEL},
			{"freq", required_argument, 0, 'f'},
			{"phylo", required_argument, 0, 'p'},
			{"alias", required_argument, 0, 'a'},
			{"scale", required_argument, 0, 's'},
			{"reference", required_argument, 0, 'r'},
			{"sister1", required_argument, 0, OPT_SISTER1},
   			{"sister2", required_argument, 0, OPT_SISTER2},
			{"select-position", required_argument, 0, 'c'},
			{"print-base",no_argument,&printbase,1},
			{"help", no_argument, 0, '?'},
			{"debug", optional_argument, 0, 'd'},
			{"count",required_argument,0,OPT_COUNT},
			{0, 0, 0, 0}
		};

		int option_index = 0;
		int c = getopt_long(argc, argv, "f:x:m:p:a:s:i:r:c:",
				long_options, &option_index);
		if (c == -1) break;
		switch (c)
		{
			case 0:
				break;
			case 'm':
				mafFile = optarg;
				break;
			case 'x':
				matrixFile = optarg;
				break;
			case 'f':
				freqFile = optarg;
				break;
			case 'p':
				phyloFile = optarg;
				break;
			case 'a':
				aliasFile = optarg;
				break;
			case 'r':
				reference = optarg;
				break;
			case 'c':
				cposition = atoi(optarg);
				break;
			case 's':
				scale = atof(optarg);
				break;
			case 'd':
				if (optarg == NULL)
					debug = 1;
				else
					debug = atoi(optarg);
				break;
			case OPT_COUNT:
				totalcount = atoi(optarg);
				break;
			case OPT_SISTER1:
				sister1 = optarg;
				break;
			case OPT_SISTER2:
				sister2 = optarg;
				break;
			case OPT_INS:
				insFile = optarg;
				break;
			case OPT_DEL:
				delFile = optarg;
				break;
			case '?':
			default:
				usage();
		}
	}
	char buf[5000];
	if (!mafFile.size()) {
		std::cerr<<"You MUST specify an input maf file! (--maf)\n";
		exit(0);
	}
	if (!phyloFile.size()) {
		std::cerr<<"You must specify a phylogenetic tree file! (--phylo)\n";
		exit(0);
	}
	if (!aliasFile.size()) {
		std::cerr<<"You must specify a set of species aliases! (--alias)\n";
		exit(0);
	}
	if (!delFile.size()) {
		std::cerr<<"You MUST specify an input deletion file! (--del)\n";
		exit(0);
	}
	if (!insFile.size()) {
		std::cerr<<"You MUST specify an input insertion file! (--ins)\n";
		exit(0);
	}
	if (!sister2.size()) sister2 = reference;
	std::ifstream pfile(phyloFile.c_str());
	std::getline(pfile,line);
	sprintf(buf,line.c_str());
	Iterator *master = new Iterator(buf, 0,scale);
	master->flag_ref(sister2);
	master->flag_sis(sister1);
	master->flag_ref(reference,0);
	master->flag_ref(reference);
	load_matrices(matrixFile,freqFile,insFile,delFile);
	cache_nuc();
	
	// load aliases
	Alias *a = new Alias(aliasFile);
 	int mycount = 0;
	
	// load maf
	std::ifstream file(mafFile.c_str());
	std::vector<Iterator*> trees;
	
	
	srand48(time(NULL));
	while (std::getline(file,line)) {
		if (!line.compare(0,1,"a",1)) {
			int genomes = 0;
			MafBlock maf(a,1);
			while (std::getline(file,line)) {
				if (!line.compare(0,1,"#")) continue;
				else if (!line.compare(0,2,"s ")) {
					maf.addRow(line,reference);
				}
				else break;
			}
			maf.setSister(sister1,0);
			maf.setSister(sister2,1);
			if (!maf.hasref()) {
				if (debug) std::cerr<<"Maf does not contain reference!\n";
				continue;
			}
			if (!maf.hassister(0) || !maf.hassister(1)) {
				if (debug) std::cerr<<"Maf does not contain sister!\n";
				continue;
			}
			if (cposition && ((maf.refstart()+maf.refsize()) < cposition || (maf.refstart() > cposition))) continue;
			if (debug) std::cerr<<"Maf is loaded with all rows. Size is "<<maf.Size()<<" with "<<maf.genomes()<<" genomes.\n";
			if ((genomes = maf.genomes()) < 2) { continue; }
			if (debug) std::cerr<<"Collapsing gaps.\n";
			maf.collapse_gaps();
			maf.strip_missing();
			if (debug) std::cerr<<"Building iterator\n";
			initialize=1;
			Iterator *i = maf.build_iterator(master, _prob);
			initialize=0;
			if (debug) std::cerr<<"Key is "<<maf.key()<<"\n";
			if (debug) std::cerr<<"Tree length is "<<i->tree_len()<<"\n";
			maf.init();
			// print maf boundaries.
			std::cout<<maf.getChr(reference)<<" "<<maf.getStart(reference,1)<<" "<<maf.getEnd(reference,1)<<"\n";
			while (maf.positions()) {
				while (!maf.legal_position()) {maf++;}
				
				if (maf.positions()) {
				i->reset();
				// if you've got missing info, build a new tree.
				if (cposition && maf.currpos() != cposition) {
					maf++;
					continue;
				}
				int c = maf.set_nucs(i);
				if (c < 2) {
					maf++;
					continue;
				}
				if (debug) std::cerr<<"Set "<<c<<" species with info.\n";

				if (c!=genomes) {
					// create a new iterator from 'i' and use it.
					Iterator *is;
					initialize=1;
					is = i->flag_tree(0,0,_prob);
					initialize=0;

					if (debug) std::cerr<<"Missing info... re-treeing.\n";
					if (debug>=2) is->print_nucs();
 					run_states_anc(is);
					if (cposition) goto theend;
					if (++mycount==totalcount) goto theend;
					delete is;
				} else {
				if (debug>=2) i->print_nucs();
 				run_states_anc(i);
				
				//if (debug && cposition) i->print_state();
				if (cposition) goto theend;
 				if (++mycount==totalcount) goto theend;
				
				}
				maf++;
				}
				
			}
			std::cout<<"\n";
			delete i;
		}
	}
theend:	
	std::cerr<<"Finished.\n";

	
}

void shift2(double &a, double &b, const double c)
{
        a=b;
        b=c;
}

void shift3(double &a, double &b, double &c, const double d)
{
        a=b;
        b=c;
        c=d;
}

