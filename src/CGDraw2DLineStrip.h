// CGDraw2DLineStrip.h
#pragma once
#include "UIEventHandler.h"
#include <vector>
#include <glm/glm.hpp>

// 2D折线绘制类（继承自UIEventHandler）
class CGDraw2DLineStrip : public UIEventHandler {
public:
    CGDraw2DLineStrip(GLFWwindow* window);
    ~CGDraw2DLineStrip();

    // 事件处理重写
    virtual int OnMouseButton(GLFWwindow* window, int button, int action, int mods) override;  // 鼠标点击
    virtual int OnCursorPos(GLFWwindow* window, double xpos, double ypos) override;            // 光标移动
    virtual int Cancel(GLFWwindow* window) override;                                           // 取消操作

private:
    std::vector<glm::dvec3> mPoints;   // 折线点集（世界坐标系）
    bool mDrawing;                     // 绘制状态标志
    int mMoveCount;                    // 鼠标移动计数（用于橡皮筋效果）
    glm::dvec3 mPreTempPos1;          // 前一次临时位置（双缓冲擦除用）
    glm::dvec3 mPreTempPos2;          // 前前次临时位置（双缓冲擦除用）
};
