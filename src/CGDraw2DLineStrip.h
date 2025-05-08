// CGDraw2DLineStrip.h
#pragma once
#include "UIEventHandler.h"
#include <vector>
#include <glm/glm.hpp>

// 2D���߻����ࣨ�̳���UIEventHandler��
class CGDraw2DLineStrip : public UIEventHandler {
public:
    CGDraw2DLineStrip(GLFWwindow* window);
    ~CGDraw2DLineStrip();

    // �¼�������д
    virtual int OnMouseButton(GLFWwindow* window, int button, int action, int mods) override;  // �����
    virtual int OnCursorPos(GLFWwindow* window, double xpos, double ypos) override;            // ����ƶ�
    virtual int Cancel(GLFWwindow* window) override;                                           // ȡ������

private:
    std::vector<glm::dvec3> mPoints;   // ���ߵ㼯����������ϵ��
    bool mDrawing;                     // ����״̬��־
    int mMoveCount;                    // ����ƶ�������������Ƥ��Ч����
    glm::dvec3 mPreTempPos1;          // ǰһ����ʱλ�ã�˫��������ã�
    glm::dvec3 mPreTempPos2;          // ǰǰ����ʱλ�ã�˫��������ã�
};
