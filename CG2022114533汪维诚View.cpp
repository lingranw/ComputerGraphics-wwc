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

// CG2022114533汪维诚View.cpp: CCG2022114533汪维诚View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CG2022114533汪维诚.h"
#endif

#include "MainFrm.h" 
#include "UIEventHandler.h" 

#include "CG2022114533汪维诚Doc.h"
#include "CG2022114533汪维诚View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCG2022114533汪维诚View

IMPLEMENT_DYNCREATE(CCG2022114533汪维诚View, CView)

BEGIN_MESSAGE_MAP(CCG2022114533汪维诚View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CCG2022114533汪维诚View 构造/析构

CCG2022114533汪维诚View::CCG2022114533汪维诚View() noexcept
{
	// TODO: 在此处添加构造代码

}

CCG2022114533汪维诚View::~CCG2022114533汪维诚View()
{
	if (m_glfwWindow) {
		glfwDestroyWindow(m_glfwWindow);
		glfwTerminate();
	}
}

BOOL CCG2022114533汪维诚View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCG2022114533汪维诚View 绘图
bool CCG2022114533汪维诚View::InitGLFW()
{
	if (!glfwInit()) {
		AfxMessageBox(_T("GLFW初始化失败"));
		return false;
	}

	// 设置GLFW窗口无边框、透明（避免覆盖MFC控件） 
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

	// 设置OpenGL版本 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //如果使用OpenGL核心模式 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //如果使用OpenGL兼容模式 

	// 创建隐藏的GLFW窗口 
	m_glfwWindow = glfwCreateWindow(100, 100, "", NULL, NULL);
	if (!m_glfwWindow) {
		AfxMessageBox(_T("Failed to glfwCreateWindow"));
		glfwTerminate();
		return false;
	}

	// 获取GLFW窗口的HWND并设置为MFC视图的子窗口 
	m_hWndGL = glfwGetWin32Window(m_glfwWindow);
	SetWindowLong(m_hWndGL, GWL_STYLE, WS_VISIBLE);
	::SetParent(m_hWndGL, GetSafeHwnd());
	::ShowWindow(m_hWndGL, SW_SHOW);

	// 初始化OpenGL上下文 
	glfwMakeContextCurrent(m_glfwWindow);

#if defined(_USE_GLEW) 
	glewInit();
#else 
	//使用GLAD来加载OpenGL的函数地址 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		AfxMessageBox(_T("Failed to initialize GLAD"));
		return false;
	}
#endif 

	// 设置视口 
	CRect rect;
	GetClientRect(&rect);
	glViewport(0, 0, rect.Width(), rect.Height());

	m_bGLInitialized = true;

	//设置回调函数用到的指针（this-当前view） 
	glfwSetWindowUserPointer(m_glfwWindow, this); //this也是CCGRenderContext*类型 
	//设置键盘输入回调 
	glfwSetKeyCallback(m_glfwWindow, UIEventHandler::KeyCallback);
	//设置鼠标按键回调 
	glfwSetMouseButtonCallback(m_glfwWindow, UIEventHandler::MouseButtonCallback);
	//设置光标移动回调 
	glfwSetCursorPosCallback(m_glfwWindow, UIEventHandler::CursorPosCallback);
	//设置鼠标滚轮回调 
	glfwSetScrollCallback(m_glfwWindow, UIEventHandler::ScrollCallback);
	return true;
}
void CCG2022114533汪维诚View::RenderScene()
{
	if (!m_bGLInitialized)
		return;
	//启用渲染环境 
	glfwMakeContextCurrent(m_glfwWindow);

	//此处添加自定义OpenGL渲染代码... 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	int x[12] = {700,673,600,500,400,326,300,326,400,500,600,673};
	int y[12] = {500,600,673,700,673,600,500,400,326,300,326,400};
	//12边形
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			DDALine(x[i]-250, y[i]+200, x[j]-250, y[j]+200, glm::vec3(0.0f, 0.0f, 0.0f));
			MidpointLine(x[i]+150, y[i]+200, x[j]+150, y[j]+200, glm::vec3(0.0f, 0.0f, 0.0f));
			BresenhamLine(x[i] + 550, y[i]+200, x[j] + 550, y[j]+200, glm::vec3(0.0f, 0.0f, 0.0f));
		}
	}
	//中点画圆法和Bresenham画圆法
	//同心圆
	for (int i = 1; i < 100; i = i + 2)
	{
		MidpointCircle(300, 300, i, glm::vec3(0.0f, 0.0f, 0.0f));
		BresenhamCircle(300, 500, i, glm::vec3(0.0f, 0.0f, 0.0f));
	}
		
	//不同位置圆
	for (int i = 0; i < 5; i++)
	{
		MidpointCircle(400 + i * 100, 400, 100, glm::vec3(0.0f, 0.0f, 0.0f));
		BresenhamCircle(400 + i * 100, 100, 100, glm::vec3(0.0f, 0.0f, 0.0f));
	}
	for (int i=30;i<=360;i=i+30)
	{
		DrawArc(i*4, 100, 50, 30, i, glm::vec3(0.0f, 0.0f, 0.0f));
	}
	*/ 
	////扫描线填充算法
	//scanlineFillTest();
	////种子填充算法
	//BresenhamCircle(300, 300, 50, glm::vec3(0.0f, 0.0f, 0.0f));
	////边界表示
	//BoundaryFill(300, 300, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	////使用内点表示对已填充区域进行覆盖
	//FloodFill(300, 300, glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	
	// 此处添加自定义OpenGL渲染代码... 

	CCG2022114533汪维诚Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		pDoc->RenderScene((CGRenderContext*)this);
	}
	//绘制完毕，交换缓存
	glfwSwapBuffers(m_glfwWindow);
	
}
void CCG2022114533汪维诚View::OnDraw(CDC* /*pDC*/)
{
	CCG2022114533汪维诚Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码 
	RenderScene();
}

void CCG2022114533汪维诚View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCG2022114533汪维诚View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCG2022114533汪维诚View 诊断

#ifdef _DEBUG
void CCG2022114533汪维诚View::AssertValid() const
{
	CView::AssertValid();
}

void CCG2022114533汪维诚View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCG2022114533汪维诚Doc* CCG2022114533汪维诚View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚Doc)));
	return (CCG2022114533汪维诚Doc*)m_pDocument;
}
#endif //_DEBUG


// CCG2022114533汪维诚View 消息处理程序

int CCG2022114533汪维诚View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码 
	if (!InitGLFW())
		return -1;

	return 0;
}

void CCG2022114533汪维诚View::OnDestroy()
{
	if (m_glfwWindow) {
		glfwDestroyWindow(m_glfwWindow);
		glfwTerminate();
		m_glfwWindow = nullptr;
	}

	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}

BOOL CCG2022114533汪维诚View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值 


	//return CView::OnEraseBkgnd(pDC); 
	return TRUE; // 禁用背景擦除
}

void CCG2022114533汪维诚View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码 
	if (m_hWndGL) {
		// 调整GLFW子窗口大小与视图客户区匹配 
		::SetWindowPos(m_hWndGL, NULL, 0, 0, cx, cy, SWP_NOZORDER);
		glfwMakeContextCurrent(m_glfwWindow);
		glViewport(0, 0, cx, cy);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		//基本图形生成算法实验部分，假定观察窗口与视口一致。（左下角为原点，右上角为(cx,cy)） 
		//使用正交平行投影 
		/* glOrtho(0, cx,    //x范围 
			0, cy,     //y范围 
			-10000.0f, 10000.0f);  //z范围（深度） */
		//调为左右对称 
		glOrtho(-cx / 2.0f, cx / 2.0f, //x范围 
			-cy/2.0f, cy/2.0f, //y范围 
			 -10000.0f, 10000.0f); //z 范围（深度） 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
}
//状态栏上显示提示信息 
void CCG2022114533汪维诚View::ShowPrompt(const std::string& str)
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	if (pMainWnd != nullptr)
	{
		pMainWnd->ShowPrompt(CString(str.c_str()));
	}
}

//状态栏上显示坐标信息 
void CCG2022114533汪维诚View::ShowCoord(double x, double y)
{
	CString str;
	glm::dvec3 v = DCS2WCS(glm::dvec3(x, y, 0.0));
	str.Format(_T("视口坐标 (%.0f, %.0f) : 世界坐标 (%.2f, %.2f) "), x, y, v.x, v.y);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	if (pMainWnd != nullptr)
	{
		pMainWnd->ShowCoord(str); //显示到状态栏 
	}
}

glm::dvec3 CCG2022114533汪维诚View::DCS2WCS(const glm::dvec3& p)
{
	//暂时使用屏幕设备坐标 
	int w, h;
	glfwGetWindowSize(m_glfwWindow, &w, &h);
	//return glm::dvec3(p.x, double(h) - p.y, 0.0);
	return glm::dvec3(p.x - double(w) / 2, double(h) / 2 - p.y, 0.0);
}

glm::dvec3 CCG2022114533汪维诚View::WCS2DCS(const glm::dvec3& p)
{
	//待实现 
	return glm::dvec3();
}
bool CCG2022114533汪维诚View::AddRenderable(std::shared_ptr<CGNode> r) const
{
	CCG2022114533汪维诚Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return false;
	return pDoc->AddRenderable(r);
}