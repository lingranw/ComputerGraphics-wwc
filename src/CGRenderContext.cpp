#include "pch.h"
#include "CGRenderContext.h"

CCGRenderContext::CCGRenderContext()
{
}
CCGRenderContext::~CCGRenderContext()
{
}
// ����GL_POINTS������
void CCGRenderContext::drawPoints(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(200, 200);
    glVertex2d(300, 300);
    glVertex2d(400, 400);
    glEnd();
}
// ����GL_LINES������
void CCGRenderContext::drawLines(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // ��ɫ����
    glBegin(GL_LINES);
    glVertex2d(100, 300);
    glVertex2d(200, 400);
    glVertex2d(200, 300);
    glVertex2d(400, 400);
    glVertex2d(100, 400);
    glVertex2d(500, 100);
    glEnd();
}
// ���պ�����
void CCGRenderContext::drawStrip(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // ��ɫ����
    glBegin(GL_LINE_STRIP);
    glVertex2d(100, 400);   // �������
    glVertex2d(500, 200);   // ���µ㣨������߶��γɽ��棩
    glVertex2d(500, 400);   // ����ת�۵�
    glEnd();
}
void CCGRenderContext::drawLoop(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // ��ɫ����
    glBegin(GL_LINE_LOOP);
    glVertex2d(100, 300);
    glVertex2d(200, 400);
    glVertex2d(200, 300);
    glVertex2d(400, 400);
    glEnd();
}
void CCGRenderContext::drawTriangles(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // ��ɫ����
    glBegin(GL_TRIANGLES);
    glVertex2d(100, 300);
    glVertex2d(200, 400);
    glVertex2d(200, 300);
    glVertex2d(50, 50);
    glVertex2d(100, 100);
    glVertex2d(200, 100);
    glEnd();
}
void CCGRenderContext::drawTriangle_Strip(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT); // ����ƽ̹��ɫģʽ

    glBegin(GL_TRIANGLE_STRIP);
    // ������1����ɫ��
    glColor3f(1.0, 0.0, 0.0);  // ��ɫ
    glVertex2d(200, 200);      // ����1
    glVertex2d(200, 100);      // ����2
    glColor3f(1.0, 0.0, 0.0);  // ���ֺ�ɫ�����Ƶ�һ����������ɫ��
    glVertex2d(300, 200);      // ����3

    // ������2����ɫ��
    glColor3f(0.0, 1.0, 0.0);  // ��ɫ
    glVertex2d(400, 100);      // ����4

    // ������3����ɫ��
    glColor3f(0.0, 0.0, 1.0);  // ��ɫ
    glVertex2d(500, 200);      // ����5
    glEnd();
}
void CCGRenderContext::drawTriangle_Fan(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT); // ����ƽ̹��ɫģʽ
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);  // ��ɫ
    glVertex2d(100, 100);
    glVertex2d(100, 200);
    glColor3f(1.0, 0.0, 0.0);  // ���ֺ�ɫ�����Ƶ�һ����������ɫ��
    glVertex2d(150, 170);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2d(170, 130);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2d(150, 70);
    glEnd();
}
void CCGRenderContext::drawQuads(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // ��ɫ����
    glBegin(GL_QUADS);
    glVertex2d(100, 100);
    glVertex2d(100, 0);
    glVertex2d(0, 0);
    glVertex2d(0, 100);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2d(400, 400);
    glVertex2d(100, 400);
    glVertex2d(100, 100);
    glVertex2d(400, 100);
    glEnd();
}
void CCGRenderContext::drawQuad_Strip(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT); // ����ƽ̹��ɫģʽ
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 0.0, 0.0);  // ��ɫ
    glVertex2d(0, 0);
    glVertex2d(100, 0);
    glVertex2d(0, 100);
    glColor3f(1.0, 0.0, 0.0);  // ���ֺ�ɫ
    glVertex2d(100, 100);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2d(100, 400);
    glVertex2d(400, 400);
    glEnd();
}
void CCGRenderContext::drawPolygon(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // ��ɫ����
    glBegin(GL_POLYGON);
    glVertex2d(100, 100);
    glVertex2d(200, 130);
    glVertex2d(170, 70);
    glVertex2d(70, 40);
    glEnd();
}
void CCGRenderContext::drawStar(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    float R = 100, r = 40;
    float a = 200.0f, b = 300.0f;
    float c = a, d = b - 100;
    bool isWhite = true; // ��ɫ�����־

    // �Ȼ������������Σ��ڲ���ɫ��
    for (int i = 0; i < 10; ++i) {
        glBegin(GL_TRIANGLES);
        // ���������ɫ���������棩
        if (isWhite) {
            glColor3f(1.0f, 1.0f, 0.0f); // ��ɫ���ɫ
        }
        else {
            glColor3f(1.0f, 0.5f, 0.0f); // ��ɫ���ɫ
        }
        isWhite = !isWhite;

        // ����ԭʼ�������ݻ���������
        switch (i) {
        case 0: glVertex2f(200, 200); glVertex2f(200, 300); glVertex2f(c - 0.59 * r, d + 0.81 * r); break;
        case 1: glVertex2f(200, 200); glVertex2f(c - 0.59 * r, d + 0.81 * r); glVertex2f(a - 0.95 * R, b - R + 0.31 * R); break;
        case 2: glVertex2f(200, 200); glVertex2f(a - 0.95 * R, b - R + 0.31 * R); glVertex2f(c - 0.95 * r, d - 0.31 * r); break;
        case 3: glVertex2f(200, 200); glVertex2f(c - 0.95 * r, d - 0.31 * r); glVertex2f(a - 0.59 * R, b - R - 0.81 * R); break;
        case 4: glVertex2f(200, 200); glVertex2f(a - 0.59 * R, b - R - 0.81 * R); glVertex2f(c, d - r); break;
        case 5: glVertex2f(200, 200); glVertex2f(c, d - r); glVertex2f(a + 0.59 * R, b - R - 0.81 * R); break;
        case 6: glVertex2f(200, 200); glVertex2f(a + 0.59 * R, b - R - 0.81 * R); glVertex2f(c + 0.95 * r, d - 0.31 * r); break;
        case 7: glVertex2f(200, 200); glVertex2f(c + 0.95 * r, d - 0.31 * r); glVertex2f(a + 0.95 * R, b - R + 0.31 * R); break;
        case 8: glVertex2f(200, 200); glVertex2f(a + 0.95 * R, b - R + 0.31 * R); glVertex2f(c + 0.59 * r, d + 0.81 * r); break;
        case 9: glVertex2f(200, 200); glVertex2f(c + 0.59 * r, d + 0.81 * r); glVertex2f(200, 300); break;
        }
        glEnd();
    }

    // �ٻ��ƺ�ɫ�����ɫ���߿�
    glColor3f(1.0f, 0.5f, 0.0f); // ��ɫ���ɫ
    glLineWidth(2.0f);           // �߿�2����
    for (int i = 0; i < 10; ++i) {
        glBegin(GL_LINE_LOOP);
        switch (i) {
        case 0: glVertex2f(200, 200); glVertex2f(200, 300); glVertex2f(c - 0.59 * r, d + 0.81 * r); break;
        case 1: glVertex2f(200, 200); glVertex2f(c - 0.59 * r, d + 0.81 * r); glVertex2f(a - 0.95 * R, b - R + 0.31 * R); break;
        case 2: glVertex2f(200, 200); glVertex2f(a - 0.95 * R, b - R + 0.31 * R); glVertex2f(c - 0.95 * r, d - 0.31 * r); break;
        case 3: glVertex2f(200, 200); glVertex2f(c - 0.95 * r, d - 0.31 * r); glVertex2f(a - 0.59 * R, b - R - 0.81 * R); break;
        case 4: glVertex2f(200, 200); glVertex2f(a - 0.59 * R, b - R - 0.81 * R); glVertex2f(c, d - r); break;
        case 5: glVertex2f(200, 200); glVertex2f(c, d - r); glVertex2f(a + 0.59 * R, b - R - 0.81 * R); break;
        case 6: glVertex2f(200, 200); glVertex2f(a + 0.59 * R, b - R - 0.81 * R); glVertex2f(c + 0.95 * r, d - 0.31 * r); break;
        case 7: glVertex2f(200, 200); glVertex2f(c + 0.95 * r, d - 0.31 * r); glVertex2f(a + 0.95 * R, b - R + 0.31 * R); break;
        case 8: glVertex2f(200, 200); glVertex2f(a + 0.95 * R, b - R + 0.31 * R); glVertex2f(c + 0.59 * r, d + 0.81 * r); break;
        case 9: glVertex2f(200, 200); glVertex2f(c + 0.59 * r, d + 0.81 * r); glVertex2f(200, 300); break;
        }
        glEnd();
    }
}
//DDA���߷�
void CCGRenderContext::DDALine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color)
{
    // ���������ֵ
    int dx = xEnd - xStart;
    int dy = yEnd - yStart;

    // ȷ��������ȡx,y�����ֵ�ľ���ֵ�ϴ��ߣ�
    int steps;
    if (abs(dx) >= abs(dy))
        steps = abs(dx);  // ˮƽ����Ϊ����
    else
        steps = abs(dy);  // ��ֱ����Ϊ����

    // �������յ��غϣ�ֱ�ӷ���
    if (steps == 0)
        return;

    // ��ʼ�������������ʹ�ø�������֤��ֵ���ȣ�
    float x = (float)xStart;    // ��ǰx���꣨���㾫�ȣ�
    float y = (float)yStart;    // ��ǰy���꣨���㾫�ȣ�
    float x_inc = (float)dx / steps;  // x����ÿ������
    float y_inc = (float)dy / steps;  // y����ÿ������

    glColor3f(color.r, color.g, color.b);

    // ��ʼ������ɢ�㼯
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        // �Ը����������������������ص�,+0.5 ��Ϊ��ʵ�����������ȡ��Ч��
        glVertex2d((int)(x + 0.5), (int)(y + 0.5));

        // ���������������������
        x += x_inc;
        y += y_inc;
    }
    glEnd();
}
// �е㻭�߷�
void CCGRenderContext::MidpointLine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color)
{
    // ���������ֵ�;���ֵ
    int dx = xEnd - xStart;
    int dy = yEnd - yStart;
    int abs_dx = abs(dx);
    int abs_dy = abs(dy);

    // ȷ����������
    int x_inc = (dx > 0) ? 1 : -1;
    int y_inc = (dy > 0) ? 1 : -1;

    // ��ʼ����ǰ����
    int x = xStart;
    int y = yStart;

    // ���û�����ɫ
    glColor3f(color.r, color.g, color.b);

    // ��ʼ���Ƶ�
    glBegin(GL_POINTS);

    if (abs_dx >= abs_dy) {
        // ˮƽ������б�ʾ���ֵ <= 1��
        int err = 2 * abs_dy - abs_dx;
        for (int i = 0; i <= abs_dx; ++i) {
            glVertex2d(x, y);
            if (err >= 0) {
                y += y_inc;
                err -= 2 * abs_dx;
            }
            err += 2 * abs_dy;
            x += x_inc;
        }
    }
    else {
        // ��ֱ������б�ʾ���ֵ > 1��
        int err = 2 * abs_dx - abs_dy;
        for (int i = 0; i <= abs_dy; ++i) {
            glVertex2d(x, y);
            if (err >= 0) {
                x += x_inc;
                err -= 2 * abs_dy;
            }
            err += 2 * abs_dx;
            y += y_inc;
        }
    }

    glEnd();
}
// Bresenham���߷�
void CCGRenderContext::BresenhamLine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color)
{
    // ���������ֵ�;���ֵ
    int dx = abs(xEnd - xStart);
    int dy = abs(yEnd - yStart);

    // ȷ����������
    int sx = (xStart < xEnd) ? 1 : -1;
    int sy = (yStart < yEnd) ? 1 : -1;

    // ��ʼ�����ֵ
    int err = dx - dy;

    // ���û�����ɫ
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    // ��ʼ��
    int x = xStart;
    int y = yStart;
    glVertex2i(x, y);

    // ��ѭ��
    while (x != xEnd || y != yEnd) {
        int e2 = 2 * err;

        // X���򲽽�
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }

        // Y���򲽽�
        if (e2 < dx) {
            err += dx;
            y += sy;
        }

        glVertex2i(x, y);
    }

    glEnd();
}
// �е㻭Բ��
void CCGRenderContext::MidpointCircle(int centerX, int centerY, int radius, glm::vec3 color) {
    // ��ʼ�����߲���������
    int x = 0;
    int y = radius;
    int d = 1 - radius; // ��ʼ���߲���

    // ���û�����ɫ
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    // ���Ƴ�ʼ�˷�Բ��
    auto drawOctantPoints = [&](int x, int y) 
        {
        glVertex2i(centerX + x, centerY + y);
        glVertex2i(centerX - x, centerY + y);
        glVertex2i(centerX + x, centerY - y);
        glVertex2i(centerX - x, centerY - y);
        glVertex2i(centerX + y, centerY + x);
        glVertex2i(centerX - y, centerY + x);
        glVertex2i(centerX + y, centerY - x);
        glVertex2i(centerX - y, centerY - x);
        };

    // ��ѭ��
    while (x <= y) {
        drawOctantPoints(x, y);

        // ���¾��߲���
        if (d < 0) {
            d += 2 * x + 3;
        }
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    glEnd();
}
//Bresenham��Բ��
void CCGRenderContext::BresenhamCircle(int centerX, int centerY, int radius, glm::vec3 color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius; // ��ʼ�����߲���

    // ���û�����ɫ
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    // �˷���Գƻ��ƺ���
    auto drawCirclePoints = [&](int x, int y)
        {
            glVertex2i(centerX + x, centerY + y);
            glVertex2i(centerX - x, centerY + y);
            glVertex2i(centerX + x, centerY - y);
            glVertex2i(centerX - x, centerY - y);
            glVertex2i(centerX + y, centerY + x);
            glVertex2i(centerX - y, centerY + x);
            glVertex2i(centerX + y, centerY - x);
            glVertex2i(centerX - y, centerY - x);
        };

    // ������ѭ��
    while (x <= y) 
    {
        drawCirclePoints(x, y);

        // ���¾��߲���
        if (d < 0) 
        {
            d = d + 4 * x + 6;
        }
        else 
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd();
}
//����(�򵥼�����)
//void CCGRenderContext::DrawArc(int centerX, int centerY, int r, double start_angle, double end_angle, glm::vec3 color) {
//    float radians_start = glm::radians(start_angle);
//    float radians_end = glm::radians(end_angle);
//    double x = r * cos(radians_start);
//    double y = r * sin(radians_start);
//    glColor3f(color.r, color.g, color.b);
//    glBegin(GL_POINTS);
//    for (double angle = radians_start; angle <= radians_end; angle += 0.01) {
//        x = r * cos(angle);
//        y = r * sin(angle);
//        glVertex2i(centerX - y, centerY - x);
//    }
//    glEnd();
//}
//����(������ת)
void CCGRenderContext::DrawArc(int centerX, int centerY, int r, double start_angle, double end_angle, glm::vec3 color) {
    float radians_start = glm::radians(start_angle);
    float radians_end = glm::radians(end_angle);
    float step = 0.01f; // ���ƻ���ƽ���ȣ��ǶȲ�������λ�����ȣ�

    // ��ʼ��
    double x = cos(radians_start);
    double y = sin(radians_start);

    // ������ת����
    double delta = step;
    double cos_delta = cos(delta);
    double sin_delta = sin(delta);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    double angle = radians_start;
    while (angle <= radians_end) {
        glVertex2i(centerX + static_cast<int>(r * x), centerY + static_cast<int>(r * y));

        // ������ת
        double new_x = x * cos_delta - y * sin_delta;
        double new_y = x * sin_delta + y * cos_delta;
        x = new_x;
        y = new_y;

        angle += delta;
    }

    glEnd();
}
// ɨ��������㷨
// �߱�ṹ��
struct Edge
{
    float x_curr; // ��ǰ��x����
    float delta_x; // y+1ʱx����������б�ʵ�����
    int y_max; // �ñ�y���ֵ
    Edge* next;
    Edge(float x, float deltax, int ymax) :x_curr(x), delta_x(deltax), y_max(ymax), next(nullptr) {}
};
void CCGRenderContext::scanlineFill(std::vector<glm::ivec2>vtxs, glm::vec3 color)
{
    if (vtxs.empty()) return;
    // �����߱�
    std::vector<Edge*>EdgeTable(2048, nullptr);
    const int n = vtxs.size();
    for (int i = 0; i < n; i++)
    {
        const glm::ivec2& v1 = vtxs[i];
        const glm::ivec2& v2 = vtxs[(i + 1) % n];
        if (v1.y == v2.y)
            continue;// ����ˮƽ��
        // ȷ�����¶˵�
        const int ymax = std::max(v1.y, v2.y);
        const int ymin = std::min(v1.y, v2.y);
        const float x = (v1.y < v2.y) ? v1.x : v2.x;
        const float deltax = (v1.x - v2.x) / static_cast<float>(v1.y - v2.y);
        // ����߱�
        Edge* newEdge = new Edge(x, deltax, ymax);
        if (!EdgeTable[ymin])// ���߱�Ϊ��
            EdgeTable[ymin] = newEdge;
        else
        {
            Edge *curr = EdgeTable[ymin];
            Edge* prev = nullptr;
            while (curr && curr->x_curr < newEdge->x_curr)
            {
                prev = curr;
                curr = curr->next;
            }
            if (!prev)// ��������ͷ��
            {
                newEdge->next = EdgeTable[ymin];
                EdgeTable[ymin] = newEdge;
            }
            else// ���������м�
            {
                prev->next = newEdge;
                newEdge->next = curr;
            }
        }
    }
    // ��ʼ�����Ա߱�
    std::vector<Edge*> ActiveEdges;
    int scanY = 0;
    // �ҵ�����ཻ��
    while (scanY < 2048 && !EdgeTable[scanY])
        scanY++;
    // ��ʼѭ��ɨ��
    while (scanY < 2048 || !ActiveEdges.empty())
    {
        if (scanY < 2048)
        {
            Edge* entry = EdgeTable[scanY];
            while (entry)
            {
                // �����߸�������AET
                Edge* newEdge = new Edge(*entry);
                ActiveEdges.push_back(newEdge);
                entry = entry->next;
            }
        }
        // ��X����������Ա߱�
        std::sort(ActiveEdges.begin(), ActiveEdges.end(),
            [](const Edge* a, const Edge* b) {
                return a->x_curr < b->x_curr;
            });
        // �ɶ��������
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_POINTS);
        for (size_t i = 0; i < ActiveEdges.size(); i += 2)
        {
            if (i + 1 >= ActiveEdges.size()) break;
            const int xStart = static_cast<int>(std::ceil(ActiveEdges[i]->x_curr));// ����ȡ��
            const int xEnd = static_cast<int>(std::floor(ActiveEdges[i + 1]->x_curr));// ����ȡ��
            for (int x = xStart; x <= xEnd; ++x) 
            {
                glVertex2i(x, scanY);
            }
        }
        glEnd();
        
        scanY++; // ������һ��ɨ����
        // ���»��Ա߱�
        auto it = ActiveEdges.begin();
        while (it != ActiveEdges.end())
        {
            Edge* edge = *it;
            if (edge->y_max == scanY)
            {
                delete edge;
                it = ActiveEdges.erase(it);// �Ƴ�
            }
            else// ����x����
            {
                edge->x_curr += edge->delta_x;
                ++it;
            }
        }
    }
    // ����߱��ڴ�
    for (auto& entry : EdgeTable) 
    {
        while (entry) 
        {
            Edge* temp = entry;
            entry = entry->next;
            delete temp;
        }
    }
}
void CCGRenderContext::scanlineFillTest()
{
    std::vector<glm::ivec2>vtxs = {
        glm::ivec2(100, 100),
        glm::ivec2(100, 200),
        glm::ivec2(200, 200),
        glm::ivec2(150, 150),
        glm::ivec2(200, 100)
    };
    scanlineFill(vtxs, glm::vec3(0.0f, 0.0f, 0.0f));
}
void CCGRenderContext::BoundaryFill(int x, int y, glm::vec3 fill, glm::vec3 boundary) 
{
    // ��ȡ��ǰ������ɫ
    GLfloat pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixel);
    glm::vec3 current(pixel[0], pixel[1], pixel[2]);
    // ��ֹ�����������߽�ɫ�������ɫ
    if (current == boundary || current == fill)
        return;
    // ���������ɫ����������
    glColor3f(fill.r, fill.g, fill.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    // �ݹ�������
    BoundaryFill(x - 1, y, fill, boundary);
    BoundaryFill(x, y - 1, fill, boundary);
    BoundaryFill(x + 1, y, fill, boundary);
    BoundaryFill(x, y + 1, fill, boundary);
}
void CCGRenderContext::FloodFill(int x, int y, glm::vec3 fill, glm::vec3 old)
{
    // ��ȡ��ǰ������ɫ
    GLfloat pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixel);
    glm::vec3 current(pixel[0], pixel[1], pixel[2]);
    // ��ֹ���������������ɫ
    if (current == old)
    {
        // ���������ɫ����������
        glColor3f(fill.r, fill.g, fill.b);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        // �ݹ�������
        FloodFill(x - 1, y, fill, old);
        FloodFill(x, y - 1, fill, old);
        FloodFill(x + 1, y, fill, old);
        FloodFill(x, y + 1, fill, old);
    }
    
}