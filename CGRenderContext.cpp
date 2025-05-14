#include "pch.h"
#include "CGRenderContext.h"

CCGRenderContext::CCGRenderContext()
{
}
CCGRenderContext::~CCGRenderContext()
{
}
// 调用GL_POINTS画点阵
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
// 调用GL_LINES画线条
void CCGRenderContext::drawLines(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // 黑色线条
    glBegin(GL_LINES);
    glVertex2d(100, 300);
    glVertex2d(200, 400);
    glVertex2d(200, 300);
    glVertex2d(400, 400);
    glVertex2d(100, 400);
    glVertex2d(500, 100);
    glEnd();
}
// 不闭合折线
void CCGRenderContext::drawStrip(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // 黑色线条
    glBegin(GL_LINE_STRIP);
    glVertex2d(100, 400);   // 左上起点
    glVertex2d(500, 200);   // 右下点（与后续线段形成交叉）
    glVertex2d(500, 400);   // 右上转折点
    glEnd();
}
void CCGRenderContext::drawLoop(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // 黑色线条
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
    glColor3f(0.0, 0.0, 0.0); // 黑色线条
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
    glShadeModel(GL_FLAT); // 启用平坦着色模式

    glBegin(GL_TRIANGLE_STRIP);
    // 三角形1（红色）
    glColor3f(1.0, 0.0, 0.0);  // 红色
    glVertex2d(200, 200);      // 顶点1
    glVertex2d(200, 100);      // 顶点2
    glColor3f(1.0, 0.0, 0.0);  // 保持红色（控制第一个三角形颜色）
    glVertex2d(300, 200);      // 顶点3

    // 三角形2（绿色）
    glColor3f(0.0, 1.0, 0.0);  // 绿色
    glVertex2d(400, 100);      // 顶点4

    // 三角形3（蓝色）
    glColor3f(0.0, 0.0, 1.0);  // 蓝色
    glVertex2d(500, 200);      // 顶点5
    glEnd();
}
void CCGRenderContext::drawTriangle_Fan(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT); // 启用平坦着色模式
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);  // 红色
    glVertex2d(100, 100);
    glVertex2d(100, 200);
    glColor3f(1.0, 0.0, 0.0);  // 保持红色（控制第一个三角形颜色）
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
    glColor3f(0.0, 0.0, 0.0); // 黑色线条
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
    glShadeModel(GL_FLAT); // 启用平坦着色模式
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 0.0, 0.0);  // 红色
    glVertex2d(0, 0);
    glVertex2d(100, 0);
    glVertex2d(0, 100);
    glColor3f(1.0, 0.0, 0.0);  // 保持红色
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
    glColor3f(0.0, 0.0, 0.0); // 黑色线条
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
    bool isWhite = true; // 颜色交替标志

    // 先绘制填充的三角形（内部颜色）
    for (int i = 0; i < 10; ++i) {
        glBegin(GL_TRIANGLES);
        // 设置填充颜色（白蓝交替）
        if (isWhite) {
            glColor3f(1.0f, 1.0f, 0.0f); // 白色或黄色
        }
        else {
            glColor3f(1.0f, 0.5f, 0.0f); // 蓝色或橙色
        }
        isWhite = !isWhite;

        // 根据原始顶点数据绘制三角形
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

    // 再绘制黑色（或橙色）边框
    glColor3f(1.0f, 0.5f, 0.0f); // 黑色或橙色
    glLineWidth(2.0f);           // 线宽2像素
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
//DDA画线法
void CCGRenderContext::DDALine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color)
{
    // 计算坐标差值
    int dx = xEnd - xStart;
    int dy = yEnd - yStart;

    // 确定步数（取x,y方向差值的绝对值较大者）
    int steps;
    if (abs(dx) >= abs(dy))
        steps = abs(dx);  // 水平方向为主导
    else
        steps = abs(dy);  // 垂直方向为主导

    // 如果起点终点重合，直接返回
    if (steps == 0)
        return;

    // 初始化坐标和增量（使用浮点数保证插值精度）
    float x = (float)xStart;    // 当前x坐标（浮点精度）
    float y = (float)yStart;    // 当前y坐标（浮点精度）
    float x_inc = (float)dx / steps;  // x方向每步增量
    float y_inc = (float)dy / steps;  // y方向每步增量

    glColor3f(color.r, color.g, color.b);

    // 开始绘制离散点集
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        // 对浮点坐标四舍五入后绘制像素点,+0.5 是为了实现四舍五入的取整效果
        glVertex2d((int)(x + 0.5), (int)(y + 0.5));

        // 按计算出的增量步进坐标
        x += x_inc;
        y += y_inc;
    }
    glEnd();
}
// 中点画线法
void CCGRenderContext::MidpointLine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color)
{
    // 计算坐标差值和绝对值
    int dx = xEnd - xStart;
    int dy = yEnd - yStart;
    int abs_dx = abs(dx);
    int abs_dy = abs(dy);

    // 确定步进方向
    int x_inc = (dx > 0) ? 1 : -1;
    int y_inc = (dy > 0) ? 1 : -1;

    // 初始化当前坐标
    int x = xStart;
    int y = yStart;

    // 设置绘制颜色
    glColor3f(color.r, color.g, color.b);

    // 开始绘制点
    glBegin(GL_POINTS);

    if (abs_dx >= abs_dy) {
        // 水平主导（斜率绝对值 <= 1）
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
        // 垂直主导（斜率绝对值 > 1）
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
// Bresenham画线法
void CCGRenderContext::BresenhamLine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color)
{
    // 计算坐标差值和绝对值
    int dx = abs(xEnd - xStart);
    int dy = abs(yEnd - yStart);

    // 确定步进方向
    int sx = (xStart < xEnd) ? 1 : -1;
    int sy = (yStart < yEnd) ? 1 : -1;

    // 初始化误差值
    int err = dx - dy;

    // 设置绘制颜色
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    // 初始点
    int x = xStart;
    int y = yStart;
    glVertex2i(x, y);

    // 主循环
    while (x != xEnd || y != yEnd) {
        int e2 = 2 * err;

        // X方向步进
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }

        // Y方向步进
        if (e2 < dx) {
            err += dx;
            y += sy;
        }

        glVertex2i(x, y);
    }

    glEnd();
}
// 中点画圆法
void CCGRenderContext::MidpointCircle(int centerX, int centerY, int radius, glm::vec3 color) {
    // 初始化决策参数和坐标
    int x = 0;
    int y = radius;
    int d = 1 - radius; // 初始决策参数

    // 设置绘制颜色
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    // 绘制初始八分圆点
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

    // 主循环
    while (x <= y) {
        drawOctantPoints(x, y);

        // 更新决策参数
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
//Bresenham画圆法
void CCGRenderContext::BresenhamCircle(int centerX, int centerY, int radius, glm::vec3 color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius; // 初始化决策参数

    // 设置绘制颜色
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    // 八方向对称绘制函数
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

    // 主绘制循环
    while (x <= y) 
    {
        drawCirclePoints(x, y);

        // 更新决策参数
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
//弧线(简单极坐标)
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
//弧线(增量旋转)
void CCGRenderContext::DrawArc(int centerX, int centerY, int r, double start_angle, double end_angle, glm::vec3 color) {
    float radians_start = glm::radians(start_angle);
    float radians_end = glm::radians(end_angle);
    float step = 0.01f; // 控制弧线平滑度（角度步长，单位：弧度）

    // 初始点
    double x = cos(radians_start);
    double y = sin(radians_start);

    // 增量旋转因子
    double delta = step;
    double cos_delta = cos(delta);
    double sin_delta = sin(delta);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);

    double angle = radians_start;
    while (angle <= radians_end) {
        glVertex2i(centerX + static_cast<int>(r * x), centerY + static_cast<int>(r * y));

        // 增量旋转
        double new_x = x * cos_delta - y * sin_delta;
        double new_y = x * sin_delta + y * cos_delta;
        x = new_x;
        y = new_y;

        angle += delta;
    }

    glEnd();
}
// 扫描线填充算法
// 边表结构体
struct Edge
{
    float x_curr; // 当前的x交点
    float delta_x; // y+1时x的增量（即斜率倒数）
    int y_max; // 该边y最大值
    Edge* next;
    Edge(float x, float deltax, int ymax) :x_curr(x), delta_x(deltax), y_max(ymax), next(nullptr) {}
};
void CCGRenderContext::scanlineFill(std::vector<glm::ivec2>vtxs, glm::vec3 color)
{
    if (vtxs.empty()) return;
    // 创建边表
    std::vector<Edge*>EdgeTable(2048, nullptr);
    const int n = vtxs.size();
    for (int i = 0; i < n; i++)
    {
        const glm::ivec2& v1 = vtxs[i];
        const glm::ivec2& v2 = vtxs[(i + 1) % n];
        if (v1.y == v2.y)
            continue;// 跳过水平边
        // 确定上下端点
        const int ymax = std::max(v1.y, v2.y);
        const int ymin = std::min(v1.y, v2.y);
        const float x = (v1.y < v2.y) ? v1.x : v2.x;
        const float deltax = (v1.x - v2.x) / static_cast<float>(v1.y - v2.y);
        // 插入边表
        Edge* newEdge = new Edge(x, deltax, ymax);
        if (!EdgeTable[ymin])// 若边表为空
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
            if (!prev)// 插入链表头部
            {
                newEdge->next = EdgeTable[ymin];
                EdgeTable[ymin] = newEdge;
            }
            else// 插入链表中间
            {
                prev->next = newEdge;
                newEdge->next = curr;
            }
        }
    }
    // 初始化活性边表
    std::vector<Edge*> ActiveEdges;
    int scanY = 0;
    // 找到最低相交处
    while (scanY < 2048 && !EdgeTable[scanY])
        scanY++;
    // 开始循环扫描
    while (scanY < 2048 || !ActiveEdges.empty())
    {
        if (scanY < 2048)
        {
            Edge* entry = EdgeTable[scanY];
            while (entry)
            {
                // 创建边副本加入AET
                Edge* newEdge = new Edge(*entry);
                ActiveEdges.push_back(newEdge);
                entry = entry->next;
            }
        }
        // 按X坐标排序活性边表
        std::sort(ActiveEdges.begin(), ActiveEdges.end(),
            [](const Edge* a, const Edge* b) {
                return a->x_curr < b->x_curr;
            });
        // 成对填充像素
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_POINTS);
        for (size_t i = 0; i < ActiveEdges.size(); i += 2)
        {
            if (i + 1 >= ActiveEdges.size()) break;
            const int xStart = static_cast<int>(std::ceil(ActiveEdges[i]->x_curr));// 向上取整
            const int xEnd = static_cast<int>(std::floor(ActiveEdges[i + 1]->x_curr));// 向下取整
            for (int x = xStart; x <= xEnd; ++x) 
            {
                glVertex2i(x, scanY);
            }
        }
        glEnd();
        
        scanY++; // 处理下一条扫描线
        // 更新活性边表
        auto it = ActiveEdges.begin();
        while (it != ActiveEdges.end())
        {
            Edge* edge = *it;
            if (edge->y_max == scanY)
            {
                delete edge;
                it = ActiveEdges.erase(it);// 移除
            }
            else// 更新x坐标
            {
                edge->x_curr += edge->delta_x;
                ++it;
            }
        }
    }
    // 清理边表内存
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
    // 获取当前像素颜色
    GLfloat pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixel);
    glm::vec3 current(pixel[0], pixel[1], pixel[2]);
    // 终止条件：遇到边界色或已填充色
    if (current == boundary || current == fill)
        return;
    // 设置填充颜色并绘制像素
    glColor3f(fill.r, fill.g, fill.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    // 递归四邻域
    BoundaryFill(x - 1, y, fill, boundary);
    BoundaryFill(x, y - 1, fill, boundary);
    BoundaryFill(x + 1, y, fill, boundary);
    BoundaryFill(x, y + 1, fill, boundary);
}
void CCGRenderContext::FloodFill(int x, int y, glm::vec3 fill, glm::vec3 old)
{
    // 获取当前像素颜色
    GLfloat pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixel);
    glm::vec3 current(pixel[0], pixel[1], pixel[2]);
    // 终止条件：遇到已填充色
    if (current == old)
    {
        // 设置填充颜色并绘制像素
        glColor3f(fill.r, fill.g, fill.b);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        // 递归四邻域
        FloodFill(x - 1, y, fill, old);
        FloodFill(x, y - 1, fill, old);
        FloodFill(x + 1, y, fill, old);
        FloodFill(x, y + 1, fill, old);
    }
    
}