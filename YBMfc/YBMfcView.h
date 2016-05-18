
// YBMfcView.h : CYBMfcView 类的接口
//

#pragma once


class CYBMfcView : public CView
{
protected: // 仅从序列化创建
	CYBMfcView();
	DECLARE_DYNCREATE(CYBMfcView)

	int m_iSpeed;
	int m_iAlt;
	int m_direct;
	int m_iPitch;
	int m_iBent;
// 特性
public:
	CYBMfcDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	BOOL IsValidSpeed(int iSpeed);
	BOOL IsJiou(int iSpeed,int step);
	BOOL IsEndByTen(int iVal);
	bool DrawVerStrip(CDC* pDC, int iCurVal, int iXOrg, int top, int bottom, int step, int iMode);
	bool DrawDirectionStrip(CDC* pDC, int iCurVal, int iXYOrg, int left, int right, int step, int iMode);
	void DrawShortDashLabel(CDC* pDC, int nex, int iCurX, int iYOrg, int kdOffset, int labelOffset);
	bool DrawAttitude(CDC* pDC, int iCurBent, int iCurPitch,int cx, int cy, int r, int iMode);
	// 实现
public:
	virtual ~CYBMfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // YBMfcView.cpp 中的调试版本
inline CYBMfcDoc* CYBMfcView::GetDocument() const
   { return reinterpret_cast<CYBMfcDoc*>(m_pDocument); }
#endif

