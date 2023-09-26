
// Pen1View.cpp: CPen1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pen1.h"
#endif

#include "Pen1Doc.h"
#include "Pen1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPen1View

IMPLEMENT_DYNCREATE(CPen1View, CView)

BEGIN_MESSAGE_MAP(CPen1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CPen1View::OnSelectColor)
	ON_COMMAND(ID_SIZE_1, &CPen1View::OnSize1)
	ON_COMMAND(ID_SIZE_4, &CPen1View::OnSize4)
	ON_COMMAND(ID_SIZE_8, &CPen1View::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CPen1View::OnSize16)
	ON_COMMAND(ID_SIZE_32, &CPen1View::OnSize32)
END_MESSAGE_MAP()

// CPen1View 생성/소멸

CPen1View::CPen1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPen1View::~CPen1View()
{
}

BOOL CPen1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPen1View 그리기
#include "CLine.h"
void CPen1View::OnDraw(CDC* pDC)
{
	CPen1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc -> m_oa.GetSize();
	for (int i = 0; i < n; i++) {
		CLine* pLine =(CLine*) pDoc->m_oa[i];
		pLine->Draw(pDC);

	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPen1View 인쇄

BOOL CPen1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPen1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPen1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPen1View 진단

#ifdef _DEBUG
void CPen1View::AssertValid() const
{
	CView::AssertValid();
}

void CPen1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPen1Doc* CPen1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPen1Doc)));
	return (CPen1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPen1View 메시지 처리기
int Size;
COLORREF Col;
#include "CLine.h"
void CPen1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags == MK_LBUTTON) {
		CPen1Doc* pDoc = GetDocument();
		CLine* pLine = new CLine(opnt, point, Size, Col);
		pDoc->m_oa.Add(pLine);
		Invalidate(FALSE);
	}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
}


void CPen1View::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPen1View::OnSize1()
{
	Size = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPen1View::OnSize4()
{
	Size = 4;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPen1View::OnSize8()
{
	Size = 8;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPen1View::OnSize16()
{
	Size = 16;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPen1View::OnSize32()
{
	Size = 32;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
