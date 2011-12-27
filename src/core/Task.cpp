/**
    @file       Task.cpp
    @brief      Task implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "Platform.h"
#include "Task.h"

/*******************************************************************************
    Task
*******************************************************************************/
namespace Vela
{
    namespace Concurrent
    {

        /**
            @fn Vela::Concurrent::Task::Task()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Task::Task()
            : state_(Task::TASK_STOPPED)
        {
        }

        /**
            @fn Vela::Concurrent::Task::~Task()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Task::~Task()
        {
        }

        /**
            @fn Vela::Concurrent::Task::Run()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Task::Run()
        {
        }

        /**
            @fn Vela::Concurrent::Task::Pause()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Task::Pause()
        {
        }

        /**
            @fn Vela::Concurrent::Task::Continue()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Task::Continue()
        {
        }

        /**
            @fn Vela::Concurrent::Task::Stop()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Task::Stop()
        {
        }

        /**
            @fn Vela::Concurrent::Task::GetState()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Task::TaskState Task::GetState() const
        {
            return state_;
        }

        /**
            @fn Vela::Concurrent::Task::SetState()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Task::SetState(Task::TaskState state)
        {
            state_ = state;
        }

    }
}

