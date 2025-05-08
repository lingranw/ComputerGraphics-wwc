#include "pch.h" 
#include "CGDraw2DLineStrip.h" 
#include "CG2022114533汪维诚Doc.h"
#include "CG2022114533汪维诚View.h"
#include "CGLineStrip.h"

static void draw2dline(const glm::dvec3& s, const glm::dvec3& e) {
    glBegin(GL_LINES);          // 开始绘制线段
    glVertex2d(s.x, s.y);       // 设置起点坐标
    glVertex2d(e.x, e.y);       // 设置终点坐标
    glEnd();
}
// 构造函数：初始化绘制状态和移动计数器
CGDraw2DLineStrip::CGDraw2DLineStrip(GLFWwindow* window)
    : UIEventHandler(window),
    mDrawing(false),            // 初始状态为非绘制中
    mMoveCount(0)               // 鼠标移动计数器清零
{
}
// 析构函数
CGDraw2DLineStrip::~CGDraw2DLineStrip() {}
// 鼠标按钮事件处理函数
// 左键按下开始/添加折线点，右键按下结束绘制
int CGDraw2DLineStrip::OnMouseButton(GLFWwindow* window, int button, int action, int mods) {
    // 获取关联的视图对象
    auto view = static_cast<CCG2022114533汪维诚View*>(glfwGetWindowUserPointer(window));
    if (!view) return -1;
    // 处理左键按下事件
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        // 初始化绘制状态
        if (!mDrawing) {
            mPoints.clear();    // 清空点集
            mMoveCount = 0;     // 重置移动计数器
        }
        // 获取当前光标位置并转换为世界坐标系
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        auto pt = view->DCS2WCS(glm::dvec3(x, y, 0));
        mPoints.push_back(pt);  // 存储当前点

        mDrawing = true;        // 进入绘制状态
        view->ShowPrompt("左键添加折线点，右键结束绘制");
        return 0;
    }
    // 处理右键按下事件（结束绘制）
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        if (!mDrawing) return -1;
        // 获取最终点位置并存储
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        auto endPt = view->DCS2WCS(glm::dvec3(x, y, 0));
        if (endPt != mPoints.back()) mPoints.push_back(endPt);
        Cancel(window);  // 清除临时绘制
        // 创建折线对象并添加到渲染列表
        if (mPoints.size() >= 2) {
            view->AddRenderable(std::make_shared<CGLineStrip>(mPoints));
            view->Invalidate();     // 请求重绘
            view->UpdateWindow();   // 更新窗口
            view->ShowPrompt("折线创建成功");
        }
        else {
            view->ShowPrompt("至少需要两个点，折线未创建");
        }

        mDrawing = false;  // 退出绘制状态
        return 0;
    }
    return -1;
}
// 鼠标移动事件处理（实现橡皮筋效果）
int CGDraw2DLineStrip::OnCursorPos(GLFWwindow* window, double xpos, double ypos) {
    if (!mDrawing || mPoints.empty()) return -1;
    auto view = static_cast<CCG2022114533汪维诚View*>(glfwGetWindowUserPointer(window));
    if (!view) return -1;
    // 坐标转换：设备坐标系 -> 世界坐标系
    glm::dvec3 start = mPoints.back();
    glm::dvec3 curr = view->DCS2WCS(glm::dvec3(xpos, ypos, 0));
    // 启用XOR逻辑操作实现擦除效果
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_XOR);       // 使用异或模式
    glColor3f(1.0f, 0.0f, 0.0f);  // 设置临时线颜色为红色
    /* 橡皮筋绘制策略：
       1. 首次移动直接绘制新线
       2. 后续移动时先擦除旧线再绘制新线
       3. 使用两个位置变量实现双缓冲擦除 */
    if (mMoveCount == 0) {  // 第一次移动
        draw2dline(start, curr);
        mPreTempPos1 = curr;  // 记录当前临时位置
        mPreTempPos2 = curr;
        mMoveCount = 1;
    }
    else if (mMoveCount == 1) {  // 第二次移动
        draw2dline(start, curr);
        mPreTempPos2 = mPreTempPos1;  // 更新位置记录
        mPreTempPos1 = curr;
        mMoveCount = 2;
    }
    else {  // 后续移动
        // 擦除前一次临时线
        draw2dline(start, mPreTempPos2);
        // 绘制新临时线
        draw2dline(start, curr);
        // 更新位置记录
        mPreTempPos2 = mPreTempPos1;
        mPreTempPos1 = curr;
        ++mMoveCount;
    }
    // 恢复OpenGL状态并交换缓冲区
    glDisable(GL_COLOR_LOGIC_OP);
    glfwSwapBuffers(window);  // 双缓冲交换
    return 0;
}
// 取消绘制操作
int CGDraw2DLineStrip::Cancel(GLFWwindow* window) {
    if (!mDrawing || mMoveCount == 0) {  // 无进行中的绘制
        mDrawing = false;
        mMoveCount = 0;
        return 0;
    }
    auto view = static_cast<CCG2022114533汪维诚View*>(glfwGetWindowUserPointer(window));
    glm::dvec3 start = mPoints.back();
    // 使用XOR模式擦除最后一条临时线
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_XOR);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw2dline(start, mPreTempPos2);  // 擦除最后一条线
    // 恢复状态并交换缓冲区
    glDisable(GL_COLOR_LOGIC_OP);
    glfwSwapBuffers(window);
    // 重置状态
    mDrawing = false;
    mMoveCount = 0;
    view->ShowPrompt("操作已取消");
    return 0;
}