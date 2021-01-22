
// CounterThreadingView.h : interface of the CCounterThreadingView class
//

#pragma once
#include "CounterThreadingDoc.h"


class CCounterThreadingView : public CView
{
protected: // create from serialization only
	CCounterThreadingView() noexcept;
	DECLARE_DYNCREATE(CCounterThreadingView)
	CWinThread* pThread;
// Attributes
public:

	CCounterThreadingDoc* GetDocument() const;

// Operations
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCounterThreadingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	double v;
	double x;
    double y;
	double g;
	double a;
	double t;
	double j;
	double h;
	afx_msg void OnThreadStart();
	afx_msg void OnThreadPause();
	afx_msg void OnThreadResume();
};

#ifndef _DEBUG  // debug version in CounterThreadingView.cpp
inline CCounterThreadingDoc* CCounterThreadingView::GetDocument() const
   { return reinterpret_cast<CCounterThreadingDoc*>(m_pDocument); }
#endif

