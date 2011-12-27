/**
    @file       Scheduler.h
    @brief      OS Core Task Scheduler

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED


/*******************************************************************************
    Scheduler
*******************************************************************************/
namespace Vela
{
    namespace Concurrent
    {

        /**
            @class Vela::Concurrent::TaskSnapshot
            @brief TaskSnapshot class
            @see http://martin.hinner.info/ARM-Microcontroller-HOWTO/ARM-Microcontroller-HOWTO-7.html
        */
        struct TaskSnapshot
        {
            unsigned int registers[16];
            unsigned int cpsr;

            void *stack;
            size_t stacksize;

            int eventmask;
            int events;

            signed short priority;
            unsigned short state;   /* Running, Ready, Waiting, Suspended */

            /* Next and previous task in the queue */
            TaskSnapshot *qnext, *qprev;
        };

        /**
            @class Vela::Concurrent::Scheduler
            @brief Scheduler class
        */
        class Scheduler
        {

        };

    }
}

#endif /*SCHEDULER_H_INCLUDED*/

