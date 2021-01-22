#pragma once
#include <afxwin.h>
class CTestThread :
    public CWinThread
{
    DECLARE_DYNCREATE(CTestThread)

protected:
    CTestThread();
    virtual ~CTestThread();

public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();

protected:
    DECLARE_MESSAGE_MAP();
public:
    static UINT RunThreadFunction(LPVOID param);
};

