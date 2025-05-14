// SphereParamsDialog.cpp: 实现文件
//

#include "pch.h"
#include "CG2022114533汪维诚.h"
#include "afxdialogex.h"
#include "SphereParamsDialog.h"


// SphereParamsDialog 对话框

IMPLEMENT_DYNAMIC(SphereParamsDialog, CDialogEx)

SphereParamsDialog::SphereParamsDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INPUT_SPHERE, pParent)
	, mRadius(0)
	, mSlices(0)
	, mStacks(0)
{

}

SphereParamsDialog::~SphereParamsDialog()
{
}

void SphereParamsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_RADIUS, mRadius);
	DDX_Text(pDX, IDC_INPUT_SLICES, mSlices);
	DDX_Text(pDX, IDC_INPUT_STACKS, mStacks);
	if (pDX->m_bSaveAndValidate) {
		DDV_MinMaxFloat(pDX, mRadius, 1.0f, 500.0f);    // 半径范围1-500
		DDV_MinMaxInt(pDX, mSlices, 8, 64);              // 经度细分8-64
		DDV_MinMaxInt(pDX, mStacks, 8, 64);              // 纬度细分8-64
	}
}


BEGIN_MESSAGE_MAP(SphereParamsDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &SphereParamsDialog::OnBnClickedOk)
	ON_EN_CHANGE(IDC_INPUT_STACKS, &SphereParamsDialog::OnEnChangeEdit3)
END_MESSAGE_MAP()


// SphereParamsDialog 消息处理程序

void SphereParamsDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码 
	UpdateData(true); //取回输入框中数据到成员变量 
	CDialogEx::OnOK();
}

void SphereParamsDialog::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

BOOL SphereParamsDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
