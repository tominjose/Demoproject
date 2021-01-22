#include "pch.h"
#include "CTestThread.h"
#include "CounterThreadingView.h"

UINT CTestThread::RunThreadFunction(LPVOID param)
{
	CCounterThreadingView* pCounterThreadingView = (CCounterThreadingView*)param;
	while (1)
	{
		
		pCounterThreadingView->Invalidate();
		Sleep(500);
	}
}
