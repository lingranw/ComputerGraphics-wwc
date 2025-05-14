// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// CG2022114533汪维诚View.h: CCG2022114533汪维诚View 类的接口
//

#pragma once
#include "glIncludes.h" 
#include "CGRenderContext.h" 
#include <memory> 
#include <string>
class CGNode;

class CCG2022114533汪维诚View : public CView, public CCGRenderContext
{

protected: // 仅从序列化创建
	CCG2022114533汪维诚View() noexcept;
	DECLARE_DYNCREATE(CCG2022114533汪维诚View)

// 特性
public:
	CCG2022114533汪维诚Doc* GetDocument() const;

protected:
	GLFWwindow* m_glfwWindow = nullptr;
	HWND m_hWndGL = nullptr;
	bool m_bGLInitialized = false;

// 操作
protected:
	bool InitGLFW(); //初始化GLFW 
	void RenderScene(); //渲染函数 

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CCG2022114533汪维诚View();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);

public:
	GLFWwindow* glfwWindow() const { return m_glfwWindow; }
	void ShowPrompt(const std::string& str); //状态栏上显示提示信息 
	void ShowCoord(double x, double y);   //状态栏上显示坐标信息 
	//根据视口坐标获取对应场景坐标（二维）-调用文档类默认相机的转换函数 
	glm::dvec3 DCS2WCS(const glm::dvec3& p); //设备坐标转世界坐标 
	glm::dvec3 WCS2DCS(const glm::dvec3& p); //世界坐标转设备坐标 
	bool AddRenderable(std::shared_ptr<CGNode> r) const;
};

#ifndef _DEBUG  // CG2022114533汪维诚View.cpp 中的调试版本
inline CCG2022114533汪维诚Doc* CCG2022114533汪维诚View::GetDocument() const
   { return reinterpret_cast<CCG2022114533汪维诚Doc*>(m_pDocument); }
#endif

