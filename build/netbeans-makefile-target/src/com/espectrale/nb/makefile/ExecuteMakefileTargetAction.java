/**
    @file       ExecuteMakefileTargetAction.java
    @brief      netbeans-makefile-target implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/
package com.espectrale.nb.makefile;

import org.netbeans.api.project.Project;

import org.openide.util.NbBundle.Messages;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;
import java.util.ResourceBundle;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.logging.Logger;
import org.netbeans.api.extexecution.ExecutionDescriptor;
import org.netbeans.api.extexecution.ExecutionService;
import org.openide.DialogDisplayer;
import org.openide.NotifyDescriptor;
import org.openide.awt.*;
import org.openide.filesystems.FileObject;
import org.openide.filesystems.FileUtil;
import org.openide.util.NbBundle;


@ActionID(category = "Build",
id = "com.espectrale.nb.makefile.ExecuteMakefileTargetAction")
@ActionRegistration(iconBase = "com/espectrale/nb/makefile/HardwareChip.png",
displayName = "#CTL_ExecuteMakefileTargetAction")
@ActionReferences({
    @ActionReference(path = "Menu/BuildProject", position = 252),
    @ActionReference(path = "Toolbars/Build", position = 500),
    @ActionReference(path = "Loaders/text/x-make/Actions", position = 950)
})
@Messages("CTL_ExecuteMakefileTargetAction=Execute Makefile Target")
public final class ExecuteMakefileTargetAction implements ActionListener {

    private final Project context;
    private final ResourceBundle bundle = NbBundle.getBundle(ExecuteMakefileTargetAction.class);

    public ExecuteMakefileTargetAction(Project context) {
        this.context = context;
    }

    public void actionPerformed(ActionEvent ev) {
        try
        {
            FileObject fo = this.context.getProjectDirectory();
            String pathStr = FileUtil.normalizePath(fo.getPath() +
                                bundle.getString("bm.makefile.path"));

            String commandStr = bundle.getString("bm.makefile.command");
            String msg = "Running " + commandStr + " in "  + pathStr +
                            " for " + this.context.getProjectDirectory().getName();
            ShowStatusMessage(msg);

            List<String> cmdList = Arrays.asList(commandStr.split(" "));
            this.execute(cmdList, pathStr);
        }
        catch (Exception e)
        {
            ShowDialogMessage(e.toString());
        }
    }

    public Integer execute(final List<String> cmdlist, final String path) throws InterruptedException, ExecutionException
    {
        try
        {
            Callable<Process> processCallable = new Callable<Process>() {
                public Process call() throws IOException {
                    ProcessBuilder pb = new ProcessBuilder(cmdlist);
                    pb.directory(new File(path));
                    return pb.start();
                }
            };

            ExecutionDescriptor descriptor = new ExecutionDescriptor().frontWindow(true).controllable(true);
            ExecutionService service = ExecutionService.newService(processCallable, descriptor, "Execute Makefile Target");
            Future<Integer> task = service.run();
            return task.get();
        }
        catch (Exception e)
        {
            ShowDialogMessage(e.toString());
        }

        return -1;
    }

    private final void ShowStatusMessage(String msg)
    {
        Logger.getAnonymousLogger().warning(msg);
        StatusDisplayer.getDefault().setStatusText(msg);
    }

    private final void ShowDialogMessage(String msg)
    {
        NotifyDescriptor nd = new NotifyDescriptor.Message(msg, NotifyDescriptor.ERROR_MESSAGE);
        DialogDisplayer.getDefault().notify(nd);
    }
}

