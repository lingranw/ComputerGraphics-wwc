#pragma once
#include "afxdialogex.h"


// SphereParamsDialog 对话框

class SphereParamsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SphereParamsDialog)

public:
	SphereParamsDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SphereParamsDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUT_SPHERE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit3();
	float mRadius;
	int mSlices;
	int mStacks;
	virtual BOOL OnInitDialog();
};
