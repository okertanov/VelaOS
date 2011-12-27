/**
    @file       Language.h
    @brief      C++ Language specific

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED


/*******************************************************************************
    Language
*******************************************************************************/
namespace Vela
{
    namespace Language
    {

        /**
          @class Vela::Language::NoCopy
          @brief NoCopy class prevents copy operation on the descendant class.
        */
        class NoCopy
        {
            protected:
                /**
                    @fn Vela::Language::NoCopy::NoCopy()
                */
                NoCopy();

                /**
                    @fn Vela::Language::NoCopy::~NoCopy()
                */
                ~NoCopy();

            private:
                /**
                    @fn Vela::Language::NoCopy::NoCopy()
                */
                NoCopy(NoCopy const&);

                /**
                    @fn Vela::Language::NoCopy::operator=
                */
                NoCopy& operator=(NoCopy const&);
        };

        /**
            @class Vela::Language::NoInstance
            @brief NoInstance class prevents instantiation of the descendant class.
        */
        class NoInstance
        {
            private:
                /**
                    @fn Vela::Language::NoInstance::NoInstance()
                */
                NoInstance();

                /**
                    @fn Vela::Language::NoInstance::~NoInstance()
                */
                ~NoInstance();
        };

        /**
            @class Vela::Language::Functor
            @brief Functor class
        */
        class Functor
        {
            public:
                /**
                    @fn Vela::Language::Functor::Functor()
                */
                Functor();

                /**
                    @fn Vela::Language::Functor::~Functor()
                */
                virtual ~Functor();

                /**
                    @fn Vela::Language::Functor::Call()
                */
                virtual void Call(void) = 0;

                /**
                    @fn Vela::Language::Functor::operator()
                */
                virtual void operator()(void) = 0;

            private:
        };

        /**
            @class Vela::Language::Lambda
            @brief Lambda class
        */
        template <typename T>
        class Lambda
        {
            public:
                /**
                    @typedef Vela::Language::Lambda::LambdaType
                    @brief
                */
                /*typedef const function<T (T&)> LambdaType;*/

                /**
                    @fn Vela::Language::Lambda::Lambda()
                */
                Lambda();

                /**
                    @fn Vela::Language::Lambda::~Lambda()
                */
                virtual ~Lambda();

            private:
                /**
                    @property Vela::Language::Lambda::lambda_
                */
                /*const LambdaType& lambda_;*/
        };

    }
}

#endif /*LANGUAGE_H_INCLUDED*/

