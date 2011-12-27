/**
    @file       Fiber.h
    @brief      OS Fiber for the Tasks

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef FIBER_H_INCLUDED
#define FIBER_H_INCLUDED


/*******************************************************************************
    Fiber
*******************************************************************************/
namespace Vela
{
    namespace Concurrent
    {

        /**
            @class Vela::Concurrent::Fiber
            @brief Fiber class
        */
        class Fiber :
            public ABI::Interface,
            public Language::NoCopy,
            public Language::Functor
        {
            public:
                /**
                    @fn Vela::Concurrent::Fiber::Fiber()
                */
                Fiber();

                /**
                    @fn Vela::Concurrent::Fiber::~Fiber()
                */
                virtual ~Fiber();

                /**
                    @fn Vela::Concurrent::Fiber::Run()
                */
                virtual void Run();

                /**
                    @fn Vela::Concurrent::Fiber::Yield()
                */
                void Yield();

        };

    }
}

#endif /*FIBER_H_INCLUDED*/

