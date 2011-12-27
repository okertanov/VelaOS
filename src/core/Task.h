/**
    @file       Task.h
    @brief      OS Task

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED


/*******************************************************************************
    Task
*******************************************************************************/
namespace Vela
{
    namespace Concurrent
    {

        /**
            @class Vela::Concurrent::Task
            @brief Task class
        */
        class Task
        {
            public:
                /**
                    @enum Vela::Concurrent::Task::TaskState
                    @brief
                */
                enum TaskState
                {
                    TASK_STOPPED,
                    TASK_RUNNING,
                    TASK_PENDING
                };

                /**
                    @fn Vela::Concurrent::Task::Task()
                */
                Task();

                /**
                    @fn Vela::Concurrent::Task::~Task()
                */
                ~Task();

                /**
                    @fn Vela::Concurrent::Task::Run()
                */
                void Run();

                /**
                    @fn Vela::Concurrent::Task::Pause()
                */
                void Pause();

                /**
                    @fn Vela::Concurrent::Task::Continue()
                */
                void Continue();

                /**
                    @fn Vela::Concurrent::Task::Stop()
                */
                void Stop();

                /**
                    @fn Vela::Concurrent::Task::GetState()
                */
                TaskState GetState() const;

                /**
                    @fn Vela::Concurrent::Task::SetState()
                */
                void SetState(TaskState state);

            private:
                /**
                    @property Vela::Concurrent::Task::state_
                */
                TaskState state_;
        };

    }
}

#endif /*TASK_H_INCLUDED*/

