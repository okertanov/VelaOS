/**
    @file       ABI.h
    @brief      Application Binary Interface

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef ABI_H_INCLUDED
#define ABI_H_INCLUDED


/*******************************************************************************
    ABI
*******************************************************************************/
namespace Vela
{
    namespace ABI
    {

        /**
            @class Vela::ABI::Singleton
            @brief Singleton class
        */
        template <typename T>
        class Singleton
        {
            public:
                /**
                    @fn Vela::ABI::Singleton::GetInstance()
                */
                static T& GetInstance()
                {
                    return instance_;
                }

            protected:
                /**
                    @fn Vela::ABI::Singleton::Singleton()
                */
                Singleton();

                /**
                    @fn Vela::ABI::Singleton::~Singleton()
                */
                ~Singleton();

            private:
                /**
                    @fn Vela::ABI::Singleton::Singleton()
                */
                Singleton(Singleton const&);

                /**
                    @fn Vela::ABI::Singleton::operator=
                */
                Singleton& operator=(Singleton const&);

            private:
                /**
                    @property Vela::ABI::Singleton::instance_
                */
                static T instance_;
        };

        /**
            @class Vela::ABI::Interface
            @brief Interface class
        */
        class Interface
        {
            public:
                /**
                    @fn Vela::ABI::Interface::Interface()
                */
                Interface();

                /**
                    @fn Vela::ABI::Interface::~Interface()
                */
                virtual ~Interface();
        };

        /**
            @class Vela::ABI::Runtime
            @brief Runtime class
        */
        class Runtime
        {
            public:
                /**
                    @fn Vela::ABI::Runtime::Runtime()
                */
                Runtime();

                /**
                    @fn Vela::ABI::Runtime::~Runtime()
                */
                virtual ~Runtime();
        };

        /**
            @class Vela::ABI::Api
            @brief Api class
        */
        class Api
        {
            public:
                /**
                    @fn Vela::ABI::Api::Api()
                */
                Api();

                /**
                    @fn Vela::ABI::Api::~Api()
                */
                virtual ~Api();
        };

        /**
            @class Vela::ABI::Driver
            @brief Driver class
        */
        class Driver
        {
            public:
                /**
                    @fn Vela::ABI::Driver::Driver()
                */
                Driver();

                /**
                    @fn Vela::ABI::Driver::~Driver()
                */
                virtual ~Driver();
        };

    }
}

#endif /*ABI_H_INCLUDED*/

