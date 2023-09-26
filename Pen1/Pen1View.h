
// Pen1View.h: CPen1View 클래스의 인터페이스
//

#pragma once


class CPen1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CPen1View() noexcept;
	DECLARE_DYNCREATE(CPen1View)

// 특성입니다.
public:
	CPen1Doc* GetDocument() const;

// 작업입니다.
public:
	CPoint opnt;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPen1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelectColor();
	afx_msg void OnSize1();
	afx_msg void OnSize4();
	afx_msg void OnSize8();
	afx_msg void OnSize16();
	afx_msg void OnSize32();
};

#ifndef _DEBUG  // Pen1View.cpp의 디버그 버전
inline CPen1Doc* CPen1View::GetDocument() const
   { return reinterpret_cast<CPen1Doc*>(m_pDocument); }
#endif

