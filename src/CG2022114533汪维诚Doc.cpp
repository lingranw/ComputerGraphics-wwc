﻿// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// CG2022114533汪维诚Doc.cpp: CCG2022114533汪维诚Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CG2022114533汪维诚.h"
#endif

#include "CG2022114533汪维诚Doc.h"

#include <propkey.h>

#include "CG2022114533汪维诚View.h" 
#include "CGScene.h" 
#include "CGCamera.h" 
#include "CGTransform.h" 
#include "CGGeode.h" 
#include "CGLineSegment.h" 
#include "CGLineStrip.h" 
#include "CGRenderContext.h" 
#include "UIEventHandler.h" 
#include "CGDraw2DLineSeg.h"
#include "CGDraw2DLineStrip.h"
#include "CGSceneGraphView.h"
#include "CGModel2DTransform.h"
#include "Tessellationhints.h"
#include "CGCube.h"
#include "CGSphere.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCG2022114533汪维诚Doc

IMPLEMENT_DYNCREATE(CCG2022114533汪维诚Doc, CDocument)

BEGIN_MESSAGE_MAP(CCG2022114533汪维诚Doc, CDocument)
	ON_UPDATE_COMMAND_UI(ID_DRAW2D_LINESEG, &CCG2022114533汪维诚Doc::OnUpdateDraw2dLineseg)
	ON_COMMAND(ID_DRAW2D_LINESEG, &CCG2022114533汪维诚Doc::OnDraw2dLineseg)
	ON_COMMAND(ID_DRAW2D_LINESTRIP, &CCG2022114533汪维诚Doc::OnDraw2dLineStrip)
{
	0x0111, ((UINT)(-1)), (WORD)32774, (WORD)32774, AfxSigCmdUI, (AFX_PMSG)(static_cast< void (CCmdTarget::*)(CCmdUI*) > (&CCG2022114533汪维诚Doc::OnUpdateDraw2dLineStrip))
},
ON_COMMAND(ID_MOVEUP, &CCG2022114533汪维诚Doc::OnMoveup)
ON_COMMAND(ID_MOVEDOWN, &CCG2022114533汪维诚Doc::OnMovedown)
ON_COMMAND(ID_MOVELEFT, &CCG2022114533汪维诚Doc::OnMoveleft)
ON_COMMAND(ID_MOVERIGHT, &CCG2022114533汪维诚Doc::OnMoveright)
ON_COMMAND(ID_ROTATE, &CCG2022114533汪维诚Doc::OnRotate)
ON_COMMAND(ID_SCALE, &CCG2022114533汪维诚Doc::OnScale)
END_MESSAGE_MAP()


// CCG2022114533汪维诚Doc 构造/析构

CCG2022114533汪维诚Doc::CCG2022114533汪维诚Doc() noexcept
{
	// TODO: 在此添加一次性构造代码 
	 //构建场景 
	mScene = std::make_shared<CGScene>();


	//长方体（模型） 
	//auto c = std::make_shared<CGCube>();
	//auto h = std::make_shared<TessellationHints>();
	//c->setTessellationHints(h);
	//c->setDisplayListEnabled(true);

	////右长方体实例节点 
	//auto t1 = std::make_shared<CGTransform>(); //实列组节点 
	//auto e1 = std::make_shared<CGGeode>();  //实列叶节点 
	//auto color1 = std::make_shared<CGColor>(); //属性 
	//color1->setValue(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)); //黄色 
	//e1->gocRenderStateSet()->setRenderState(color1, -1); //设置节点属性 
	//t1->translate(100, 0, 0);
	//t1->rotate(45, 1, 1, 1);
	//t1->scale(100, 100, 100);
	//e1->AddChild(c);
	//t1->AddChild(e1);
	//mScene->GetSceneData()->asGroup()->AddChild(t1);

	////左长方体节点 
	//auto t2 = std::make_shared<CGTransform>(); //实列组节点 
	//auto e2 = std::make_shared<CGGeode>();  //实列叶节点 
	//auto color2 = std::make_shared<CGColor>(); //属性 
	//color2->setValue(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)); //蓝色 
	//e2->gocRenderStateSet()->setRenderState(color2, -1); //设置节点属性 
	//auto p = std::make_shared<CGPolygonMode>(PM_LINE, PM_LINE); //设置线框模式 
	//e2->gocRenderStateSet()->setRenderState(p, -1); //设置节点属性 
	//t2->translate(-100, 0, 0);
	//t2->rotate(45, 1, 1, 1);
	//t2->scale(100, 100, 100);
	//e2->AddChild(c);
	//t2->AddChild(e2);
	//mScene->GetSceneData()->asGroup()->AddChild(t2);

	// 在文档类构造函数中测试
	auto sphere = std::make_shared<CGSphere>(50.0f); // 半径50
	auto hints = std::make_shared<TessellationHints>();
	hints->setTargetSlices(60); // 提高细分精度
	hints->setTargetStacks(30);
	sphere->setTessellationHints(hints);
	sphere->setDisplayListEnabled(true);
	// 红色实体球体
	auto t1 = std::make_shared<CGTransform>();
	auto e1 = std::make_shared<CGGeode>();
	auto color1 = std::make_shared<CGColor>();
	color1->setValue(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)); //蓝色 
	e1->gocRenderStateSet()->setRenderState(color1, -1);
	t1->translate(200, 0, 0);
	e1->AddChild(sphere);
	t1->AddChild(e1);
	mScene->GetSceneData()->asGroup()->AddChild(t1);
	// 蓝色线框球体
	auto t2 = std::make_shared<CGTransform>();
	auto e2 = std::make_shared<CGGeode>();
	auto color2 = std::make_shared<CGColor>();
	color2->setValue(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)); //黄色 
	auto polygonMode = std::make_shared<CGPolygonMode>(PM_LINE, PM_LINE);       // 线框模式
	e2->gocRenderStateSet()->setRenderState(color2, -1);
	e2->gocRenderStateSet()->setRenderState(polygonMode, -1);
	t2->translate(-200, 0, 0);
	t2->rotate(45, 1, 1, 1);
	e2->AddChild(sphere);
	t2->AddChild(e2);
	mScene->GetSceneData()->asGroup()->AddChild(t2);
	//注释掉 
//mScene->SetMainCamera(std::make_shared<CGCamera>()); 
//auto e = std::make_shared<CGGeode>(); 
//auto line = std::make_shared<CGLineSegment>(glm::dvec3(100,100,0),glm::dvec3(400,300,0)); 
//e->AddChild(line); 
//auto g = std::make_shared<CGTransform>(); 
//g->AddChild(e); 
//mScene->SetSceneData(g); 
}

CCG2022114533汪维诚Doc::~CCG2022114533汪维诚Doc()
{
}

BOOL CCG2022114533汪维诚Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CCG2022114533汪维诚Doc 序列化

void CCG2022114533汪维诚Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CCG2022114533汪维诚Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CCG2022114533汪维诚Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CCG2022114533汪维诚Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCG2022114533汪维诚Doc 诊断

#ifdef _DEBUG
void CCG2022114533汪维诚Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCG2022114533汪维诚Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCG2022114533汪维诚Doc 命令

void CCG2022114533汪维诚Doc::OnUpdateDraw2dLineseg(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码 
	pCmdUI->SetCheck(UIEventHandler::CurCommand() && UIEventHandler::CurCommand()->GetType() ==
		EventType::Draw2DLineSeg);
}

void CCG2022114533汪维诚Doc::OnDraw2dLineseg()
{
	// TODO: 在此添加命令处理程序代码 
	if (!mSelectedGroup) {
		AfxMessageBox(_T("请先选择添加子节点的组节点！"));
		return;
	}
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}

	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}
	if (view != nullptr) {
		UIEventHandler::SetCommand(new CGDraw2DLineSeg(view->glfwWindow())); //创建绘制直线段的命令对象
	}
}

bool CCG2022114533汪维诚Doc::RenderScene(CGRenderContext* pRC)
{
	if (pRC == nullptr)
		return false;
	if (mScene == nullptr)
		return false;
	CGCamera* pCamera = mScene->GetMainCamera();
	if (pCamera == nullptr)
		return false;

	return mScene->Render(pRC, pCamera);
}
bool CCG2022114533汪维诚Doc::AddRenderable(std::shared_ptr<CGNode> r)
{
	if (mSelectedGroup) { //需要先选中一各组节点 
		//模型加入实例节点后加入场景 
		auto ge = std::make_shared<CGGeode>();
		ge->AddChild(r);
		mSelectedGroup->AddChild(ge);
		CTreeCtrl& tree = GetSceneGraphView()->GetTreeCtrl();
		InstToSceneTree(&tree, mSelectedItem, ge.get());
		return true;
	}
	else {
		AfxMessageBox(_T("请先选择添加子节点的组节点！"));
	}
	return false;
}



void CCG2022114533汪维诚Doc::OnDraw2dLineStrip()
{
	// TODO: 在此添加命令处理程序代码
	if (!mSelectedGroup) {
		AfxMessageBox(_T("请先选择添加子节点的组节点！"));
		return;
	}
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}

	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}
	if (view) {
		UIEventHandler::SetCommand(new CGDraw2DLineStrip(view->glfwWindow()));
	}
}

void CCG2022114533汪维诚Doc::OnUpdateDraw2dLineStrip(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(UIEventHandler::CurCommand() &&
		UIEventHandler::CurCommand()->GetType() == EventType::Draw2DLineStrip); // 修正事件类型
}

CCGSceneGraphView* CCG2022114533汪维诚Doc::GetSceneGraphView()
{
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCGSceneGraphView))) {
			CCGSceneGraphView* view = dynamic_cast<CCGSceneGraphView*>(pView);
			return view;
		}
	}
	return nullptr;
}
void CCG2022114533汪维诚Doc::InstToSceneTree(CTreeCtrl* pTree)
{
	TV_INSERTSTRUCT tvinsert;
	HTREEITEM hInst;
	tvinsert.hParent = NULL;
	tvinsert.hInsertAfter = TVI_LAST;
	tvinsert.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_PARAM;
	tvinsert.item.hItem = NULL;
	tvinsert.item.state = 0;
	tvinsert.item.stateMask = 0;
	tvinsert.item.cchTextMax = 40;
	tvinsert.item.cChildren = 0;
	tvinsert.item.lParam = NULL;// 
	CString str(_T("场景"));
	tvinsert.item.pszText = str.GetBuffer();
	str.ReleaseBuffer();
	hInst = pTree->InsertItem(&tvinsert);
	pTree->SetItemData(hInst, DWORD_PTR(mScene.get()));

	InstToSceneTree(pTree, hInst, mScene->GetSceneData());

	pTree->Expand(hInst, TVE_EXPAND);
}
void CCG2022114533汪维诚Doc::InstToSceneTree(CTreeCtrl* pTree, HTREEITEM hParent, CGNode* node)
{
	TV_INSERTSTRUCT tvinsert;
	HTREEITEM hTree;
	tvinsert.hParent = hParent;
	tvinsert.hInsertAfter = TVI_LAST;
	tvinsert.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_PARAM;
	tvinsert.item.hItem = NULL;
	tvinsert.item.state = 0;
	tvinsert.item.stateMask = 0;
	tvinsert.item.cchTextMax = 40;
	tvinsert.item.cChildren = 0;
	tvinsert.item.lParam = LPARAM(&node);// 
	if (node->asGeode()) {
		CString str(_T("Geode"));
		tvinsert.item.pszText = str.GetBuffer();
		str.ReleaseBuffer();
		hTree = pTree->InsertItem(&tvinsert);
		pTree->SetItemData(hTree, DWORD_PTR(node));
		//叶子实例节点不再显示模型节点 
	}
	else if (node->asTransform()) {
		CString str(_T("Trans"));
		tvinsert.item.pszText = str.GetBuffer();
		str.ReleaseBuffer();
		hTree = pTree->InsertItem(&tvinsert);
		pTree->SetItemData(hTree, DWORD_PTR(node));
		unsigned int childs = node->asTransform()->GetNumChildren();
		for (unsigned int i = 0; i < childs; i++) {
			InstToSceneTree(pTree, hTree, node->asTransform()->GetChild(i));
		}
	}
	else if (node->asGroup()) {
		CString str(_T("Group"));
		tvinsert.item.pszText = str.GetBuffer();
		str.ReleaseBuffer();
		hTree = pTree->InsertItem(&tvinsert);
		pTree->SetItemData(hTree, DWORD_PTR(node));
		unsigned int childs = node->asGroup()->GetNumChildren();
		for (unsigned int i = 0; i < childs; i++) {
			InstToSceneTree(pTree, hTree, node->asGroup()->GetChild(i));
		}
	}
}
void CCG2022114533汪维诚Doc::OnSelectSceneTreeItem(CTreeCtrl* pTree, HTREEITEM hItem)
{
	mSelectedItem = hItem;
	if (!mSelectedItem) {
		mSelectedGroup = nullptr;
		return;
	}
	HTREEITEM hRoot = pTree->GetRootItem();
	if (mSelectedItem == hRoot) {
		mSelectedGroup = nullptr;
	}
	else {
		CGGroup* node = (CGGroup*)(pTree->GetItemData(mSelectedItem));
		if (node && node->asGroup() && !(node->asGeode())) { //不允许叶子节点上再 
			mSelectedGroup = dynamic_cast<CGGroup*>(node);
		}
		else {
			mSelectedGroup = nullptr;
		}
	}
}
void CCG2022114533汪维诚Doc::OnMoveup()
{
	// TODO: 在此添加命令处理程序代码
	CCGSceneGraphView* pSceneGraphView = GetSceneGraphView();
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}
	CTreeCtrl* pTree = &pSceneGraphView->GetTreeCtrl();
	// 如果当前有正在执行的命令，先删除它
	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}

	if (view != nullptr) {
		// UIEventHandler::SetCommand(new CGModel2DTransform((CGRenderable*)pTree->GetItemData(mSelectedItem),view->glfwWindow())); 
		CGGeode* renderable = (CGGeode*)pTree->GetItemData(mSelectedItem);
		if (!renderable) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		CGNode* child = renderable->GetChild(0);
		if (!child) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		// 每次移动10个单位
		const float translateAmount = 10.0f; // 负值表示向左移动
		child->Translate(0, translateAmount);
		// 更新所有视图
		UpdateAllViews(NULL);

		// 设置状态栏提示
		view->ShowPrompt("对象已向上移动");
	}
}

void CCG2022114533汪维诚Doc::OnMovedown()
{
	// TODO: 在此添加命令处理程序代码
	CCGSceneGraphView* pSceneGraphView = GetSceneGraphView();
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}
	CTreeCtrl* pTree = &pSceneGraphView->GetTreeCtrl();
	// 如果当前有正在执行的命令，先删除它
	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}

	if (view != nullptr) {
		// UIEventHandler::SetCommand(new CGModel2DTransform((CGRenderable*)pTree->GetItemData(mSelectedItem),view->glfwWindow())); 
		CGGeode* renderable = (CGGeode*)pTree->GetItemData(mSelectedItem);
		if (!renderable) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		CGNode* child = renderable->GetChild(0);
		if (!child) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		// 每次移动10个单位
		const float translateAmount = -10.0f; // 负值表示向下移动
		child->Translate(0, translateAmount);
		// 更新所有视图
		UpdateAllViews(NULL);

		// 设置状态栏提示
		view->ShowPrompt("对象已向下移动");
	}
}

void CCG2022114533汪维诚Doc::OnMoveleft()
{
	// TODO: 在此添加命令处理程序代码
	CCGSceneGraphView* pSceneGraphView = GetSceneGraphView();
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}
	CTreeCtrl* pTree = &pSceneGraphView->GetTreeCtrl();
	// 如果当前有正在执行的命令，先删除它
	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}

	if (view != nullptr) {
		// UIEventHandler::SetCommand(new CGModel2DTransform((CGRenderable*)pTree->GetItemData(mSelectedItem),view->glfwWindow())); 
		CGGeode* renderable = (CGGeode*)pTree->GetItemData(mSelectedItem);
		if (!renderable) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		CGNode* child = renderable->GetChild(0);
		if (!child) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		// 直接应用向左平移变换（每次移动10个单位）
		const float translateAmount = -10.0f; // 负值表示向左移动
		child->Translate(translateAmount, 0);
		// 更新所有视图
		UpdateAllViews(NULL);

		// 设置状态栏提示
		view->ShowPrompt("对象已向左移动");
	}
}

void CCG2022114533汪维诚Doc::OnMoveright()
{
	// TODO: 在此添加命令处理程序代码
	CCGSceneGraphView* pSceneGraphView = GetSceneGraphView();
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}
	CTreeCtrl* pTree = &pSceneGraphView->GetTreeCtrl();
	// 如果当前有正在执行的命令，先删除它
	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}

	if (view != nullptr) {
		// UIEventHandler::SetCommand(new CGModel2DTransform((CGRenderable*)pTree->GetItemData(mSelectedItem),view->glfwWindow())); 
		CGGeode* renderable = (CGGeode*)pTree->GetItemData(mSelectedItem);
		if (!renderable) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		CGNode* child = renderable->GetChild(0);
		if (!child) {
			AfxMessageBox(_T("请先选择需要移动的子节点！"));
			return;
		}
		// 直接应用向左平移变换（每次移动10个单位）
		const float translateAmount = 10.0f; // 负值表示向左移动
		child->Translate(translateAmount, 0);
		// 更新所有视图
		UpdateAllViews(NULL);

		// 设置状态栏提示
		view->ShowPrompt("对象已向右移动");
	}
}

void CCG2022114533汪维诚Doc::OnRotate()
{
	// TODO: 在此添加命令处理程序代码
	// 顺时针旋转操作
	CCGSceneGraphView* pSceneGraphView = GetSceneGraphView();
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	CTreeCtrl* pTree = &pSceneGraphView->GetTreeCtrl();
	CGGeode* renderable = (CGGeode*)pTree->GetItemData(mSelectedItem);
	if (!renderable) {
		AfxMessageBox(_T("请先选择需要移动的子节点！"));
		return;
	}
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}
	// 如果当前有正在执行的命令，先删除它
	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}
	CGNode* child = renderable->GetChild(0);
	if (!child) {
		AfxMessageBox(_T("请先选择需要移动的子节点！"));
		return;
	}
	// 如果找到了视图，创建并设置绘制折线段的命令对象
	if (view != nullptr) {
		UIEventHandler::SetCommand(new CGModel2DTransform(child, view->glfwWindow())); //创建绘制折线的命令对象
		UpdateAllViews(NULL);
	}
}

void CCG2022114533汪维诚Doc::OnScale()
{
	// TODO: 在此添加命令处理程序代码
	CCGSceneGraphView* pSceneGraphView = GetSceneGraphView();
	CCG2022114533汪维诚View* view = nullptr;
	POSITION pos = GetFirstViewPosition();
	CTreeCtrl* pTree = &pSceneGraphView->GetTreeCtrl();
	CGGeode* renderable = (CGGeode*)pTree->GetItemData(mSelectedItem);
	if (!renderable) {
		AfxMessageBox(_T("请先选择需要移动的子节点！"));
		return;
	}
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CCG2022114533汪维诚View))) {
			view = dynamic_cast<CCG2022114533汪维诚View*>(pView);
			break;
		}
	}
	// 如果当前有正在执行的命令，先删除它
	if (UIEventHandler::CurCommand()) {
		UIEventHandler::DelCommand();
	}
	CGNode* child = renderable->GetChild(0);
	if (!child) {
		AfxMessageBox(_T("请先选择需要移动的子节点！"));
		return;
	}
	// 如果找到了视图，创建并设置绘制折线段的命令对象
	if (view != nullptr) {
		// 使用新的 CGDraw2DPolylineSegment 类
		UIEventHandler::SetCommand(new CGModel2DTransform(child, view->glfwWindow(), true, true)); //创建绘制折线的命令对象
		UpdateAllViews(NULL);
	}
}
