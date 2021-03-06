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
			// Start the thread
			void Start(bool bIsDetach);

			// Get the ThreadId
			inline unsigned long long GetId() const
			{
				return m_iThreadId;
			}

			// Set the Task
			inline void SetTask(TaskEntry& task)
			{
				SetCurTask(task);
			}

			// Set the ExitThreadPool
			void SetIsExitThreadPool(bool bExitThreadPool)
			{
				GetCurTask().SetIsExitPool(bExitThreadPool);
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
			inline TaskEntry& GetCurTask()
			{
				return m_Task;
			}

			// Set the Task
			inline void SetCurTask(TaskEntry& Task)
			{
				m_Task = Task;
			}

			// Set the ThreadId
			inline void SetId(unsigned long long iThreadId)
			{
				m_iThreadId = iThreadId;
			}

		private:
			// Thread id
			unsigned long long m_iThreadId;

			// Thread pool
			IThreadPool* m_pThreadPool;

			// Task
			TaskEntry m_Task;
		
			// Current thread
			std::thread m_CurThread;

			// Disposed status
			bool m_bDisposed;
		};
	}
}

#endif // MYTHREAD_H
