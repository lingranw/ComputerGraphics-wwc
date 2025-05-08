#include "pch.h" 
#include "CGDraw2DLineStrip.h" 
#include "CG2022114533��ά��Doc.h"
#include "CG2022114533��ά��View.h"
#include "CGLineStrip.h"

static void draw2dline(const glm::dvec3& s, const glm::dvec3& e) {
    glBegin(GL_LINES);          // ��ʼ�����߶�
    glVertex2d(s.x, s.y);       // �����������
    glVertex2d(e.x, e.y);       // �����յ�����
    glEnd();
}
// ���캯������ʼ������״̬���ƶ�������
CGDraw2DLineStrip::CGDraw2DLineStrip(GLFWwindow* window)
    : UIEventHandler(window),
    mDrawing(false),            // ��ʼ״̬Ϊ�ǻ�����
    mMoveCount(0)               // ����ƶ�����������
{
}
// ��������
CGDraw2DLineStrip::~CGDraw2DLineStrip() {}
// ��갴ť�¼�������
// ������¿�ʼ/������ߵ㣬�Ҽ����½�������
int CGDraw2DLineStrip::OnMouseButton(GLFWwindow* window, int button, int action, int mods) {
    // ��ȡ��������ͼ����
    auto view = static_cast<CCG2022114533��ά��View*>(glfwGetWindowUserPointer(window));
    if (!view) return -1;
    // ������������¼�
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        // ��ʼ������״̬
        if (!mDrawing) {
            mPoints.clear();    // ��յ㼯
            mMoveCount = 0;     // �����ƶ�������
        }
        // ��ȡ��ǰ���λ�ò�ת��Ϊ��������ϵ
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        auto pt = view->DCS2WCS(glm::dvec3(x, y, 0));
        mPoints.push_back(pt);  // �洢��ǰ��

        mDrawing = true;        // �������״̬
        view->ShowPrompt("���������ߵ㣬�Ҽ���������");
        return 0;
    }
    // �����Ҽ������¼����������ƣ�
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        if (!mDrawing) return -1;
        // ��ȡ���յ�λ�ò��洢
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        auto endPt = view->DCS2WCS(glm::dvec3(x, y, 0));
        if (endPt != mPoints.back()) mPoints.push_back(endPt);
        Cancel(window);  // �����ʱ����
        // �������߶�����ӵ���Ⱦ�б�
        if (mPoints.size() >= 2) {
            view->AddRenderable(std::make_shared<CGLineStrip>(mPoints));
            view->Invalidate();     // �����ػ�
            view->UpdateWindow();   // ���´���
            view->ShowPrompt("���ߴ����ɹ�");
        }
        else {
            view->ShowPrompt("������Ҫ�����㣬����δ����");
        }

        mDrawing = false;  // �˳�����״̬
        return 0;
    }
    return -1;
}
// ����ƶ��¼�����ʵ����Ƥ��Ч����
int CGDraw2DLineStrip::OnCursorPos(GLFWwindow* window, double xpos, double ypos) {
    if (!mDrawing || mPoints.empty()) return -1;
    auto view = static_cast<CCG2022114533��ά��View*>(glfwGetWindowUserPointer(window));
    if (!view) return -1;
    // ����ת�����豸����ϵ -> ��������ϵ
    glm::dvec3 start = mPoints.back();
    glm::dvec3 curr = view->DCS2WCS(glm::dvec3(xpos, ypos, 0));
    // ����XOR�߼�����ʵ�ֲ���Ч��
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_XOR);       // ʹ�����ģʽ
    glColor3f(1.0f, 0.0f, 0.0f);  // ������ʱ����ɫΪ��ɫ
    /* ��Ƥ����Ʋ��ԣ�
       1. �״��ƶ�ֱ�ӻ�������
       2. �����ƶ�ʱ�Ȳ��������ٻ�������
       3. ʹ������λ�ñ���ʵ��˫������� */
    if (mMoveCount == 0) {  // ��һ���ƶ�
        draw2dline(start, curr);
        mPreTempPos1 = curr;  // ��¼��ǰ��ʱλ��
        mPreTempPos2 = curr;
        mMoveCount = 1;
    }
    else if (mMoveCount == 1) {  // �ڶ����ƶ�
        draw2dline(start, curr);
        mPreTempPos2 = mPreTempPos1;  // ����λ�ü�¼
        mPreTempPos1 = curr;
        mMoveCount = 2;
    }
    else {  // �����ƶ�
        // ����ǰһ����ʱ��
        draw2dline(start, mPreTempPos2);
        // ��������ʱ��
        draw2dline(start, curr);
        // ����λ�ü�¼
        mPreTempPos2 = mPreTempPos1;
        mPreTempPos1 = curr;
        ++mMoveCount;
    }
    // �ָ�OpenGL״̬������������
    glDisable(GL_COLOR_LOGIC_OP);
    glfwSwapBuffers(window);  // ˫���彻��
    return 0;
}
// ȡ�����Ʋ���
int CGDraw2DLineStrip::Cancel(GLFWwindow* window) {
    if (!mDrawing || mMoveCount == 0) {  // �޽����еĻ���
        mDrawing = false;
        mMoveCount = 0;
        return 0;
    }
    auto view = static_cast<CCG2022114533��ά��View*>(glfwGetWindowUserPointer(window));
    glm::dvec3 start = mPoints.back();
    // ʹ��XORģʽ�������һ����ʱ��
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_XOR);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw2dline(start, mPreTempPos2);  // �������һ����
    // �ָ�״̬������������
    glDisable(GL_COLOR_LOGIC_OP);
    glfwSwapBuffers(window);
    // ����״̬
    mDrawing = false;
    mMoveCount = 0;
    view->ShowPrompt("������ȡ��");
    return 0;
}