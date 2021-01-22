
// CounterThreadingView.cpp : implementation of the CCounterThreadingView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CounterThreading.h"
#endif

#include "CounterThreadingDoc.h"
#include "CounterThreadingView.h"
#include "CTestThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCounterThreadingView

IMPLEMENT_DYNCREATE(CCounterThreadingView, CView)

BEGIN_MESSAGE_MAP(CCounterThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_THREAD_START, &CCounterThreadingView::OnThreadStart)
	ON_COMMAND(ID_THREAD_PAUSE, &CCounterThreadingView::OnThreadPause)
	ON_COMMAND(ID_THREAD_RESUME, &CCounterThreadingView::OnThreadResume)
END_MESSAGE_MAP()

// CCounterThreadingView construction/destruction

CCounterThreadingView::CCounterThreadingView() noexcept
{
	t = 0.0;
	v = 40.0;
	x = 0.0;
	y = 0.0;
	g = 9.8;
	a = 40.0;
	j = 3.14 / 180.0;
}

CCounterThreadingView::~CCounterThreadingView()
{
}

BOOL CCounterThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCounterThreadingView drawing

void CCounterThreadingView::OnDraw(CDC* pDC)
{
	CCounterThreadingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	
	CRect Recto(550, 525, 200, 255);
	pDC->Ellipse(&Recto);
	pDC->MoveTo(200, 400);
	pDC->LineTo(550, 400);
	pDC->MoveTo(200, 400);
	pDC->LineTo(200, 100);
	CBrush brush(RGB(0, 0, 0));
	CBrush* pBrush = pDC->SelectObject(&brush);
	CRect circ(200, 330, 230, 355);
	pDC->Ellipse(&circ);
	pDC->SelectObject(pBrush);

	for ( t = 1.0; t < 4.0; t++)
	{
		
		x = v * t * cos(j*a);
		CString xCounter;
		xCounter.Format(L"x= %f", x);
		y = v * t * sin(j*a) - 1/2*g*t*t;
		CString yCounter;
		yCounter.Format(L"y= %f", y);
		pDC->TextOut(100, 100, xCounter);
		pDC->TextOut(100, 150, yCounter);
		CBrush brush(RGB(0, 0, 0));
		CBrush* pBrush = pDC->SelectObject(&brush);
		CRect circ(200.0+x, 330.0-y, 230.0+x, 355.0-y);
		pDC->Ellipse(&circ);
		Invalidate();
		pDC->SelectObject(pBrush);
	}
	
}


// CCounterThreadingView printing

BOOL CCounterThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCounterThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCounterThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCounterThreadingView diagnostics

#ifdef _DEBUG
void CCounterThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterThreadingDoc* CCounterThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterThreadingDoc)));
	return (CCounterThreadingDoc*)m_pDocument;
}
#endif //_DEBUG


// CCounterThreadingView message handlers


void CCounterThreadingView::OnThreadStart()
{
	pThread = AfxBeginThread(CTestThread::RunThreadFunction, this);
}


void CCounterThreadingView::OnThreadPause()
{
	pThread->SuspendThread();
}


void CCounterThreadingView::OnThreadResume()
{
	pThread->ResumeThread();
}
