///************************************************************************
/// <copyrigth>Voice AI Technology Of ShenZhen</copyrigth>
/// <author>tangyingzhong</author>
/// <contact>yingzhong@voiceaitech.com</contact>
/// <version>v1.0.0</version>
/// <describe>
/// This is c++11 thread
///</describe>
/// <date>2020/2/28</date>
///***********************************************************************
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <thread>
#include <mutex>
#include "IThreadPool.h"

namespace System
{
	namespace Thread
	{
		class MyThread :public std::thread
		{
		public:
			// Construct the MyThread
			MyThread(IThreadPool* pThreadPool);

			// Detructe the MyThread
			virtual ~MyThread();

		private:
			// Forbid the copy MyThread
			MyThread(const MyThread& other) {	};

			// Forbid the assigment of MyThread
			MyThread& operator=(const MyThread& other) { return *this; };

		public:
			// Set thread detach
			void SetDetachState(bool bIsDetach);

			// Start the thread
			void Start();

			// Get the ThreadId
			inline unsigned long long GetId() const
			{
				return m_iThreadId;
			}

			// Set the ThreadId
			inline void SetId(unsigned long long iThreadId)
			{
				m_iThreadId = iThreadId;
			}

			// Set the Task
			inline void SetTask(TaskEntry& task)
			{
				SetCurTask(&task);
			}

			// Set the ExitThreadPool
			void SetIsExitThreadPool(bool bExitThreadPool)
			{
				GetCurTask()->SetIsExitPool(bExitThreadPool);
			}

		private:
			// Run the thread
			void Run();

			// Get thread id
			unsigned long long GetThreadId();

		private:
			// Get the disposed status
			inline bool GetDisposed() const
			{
				return m_bDisposed;
			}

			// Set the disposed status
			inline void SetDisposed(bool bDisposed)
			{
				m_bDisposed = bDisposed;
			}

			// Get the IsDetached
			inline bool GetIsDetached() const
			{
				return m_bIsDetached;
			}

			// Set the IsDetached
			inline void SetIsDetached(bool bIsDetached)
			{
				m_bIsDetached = bIsDetached;
			}

			// Get the ThreadPool
			inline IThreadPool* GetThreadPool() const
			{
				return m_pThreadPool;
			}

			// Set the ThreadPool
			inline void SetThreadPool(IThreadPool* pThreadPool)
			{
				m_pThreadPool = pThreadPool;
			}

			// Get the Task
			inline TaskEntry* GetCurTask() const
			{
				return m_pTask;
			}

			// Set the Task
			inline void SetCurTask(TaskEntry* pTask)
			{
				m_pTask = pTask;
			}

		private:
			// Thread id
			unsigned long long m_iThreadId;

			// Thread pool
			IThreadPool* m_pThreadPool;

			// Task
			TaskEntry* m_pTask;
		
			// Current thread
			std::thread m_CurThread;

			// Thread detach state
			bool m_bIsDetached;

			// Disposed status
			bool m_bDisposed;
		};
	}
}

#endif // MYTHREAD_H
