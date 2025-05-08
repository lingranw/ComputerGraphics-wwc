// CGLineStrip.cpp
#include "pch.h"
#include "CGLineStrip.h"

IMPLEMENT_SERIAL(CGLineStrip, CGGeometry, 1)

CGLineStrip::CGLineStrip() {}
CGLineStrip::CGLineStrip(const std::vector<glm::dvec3>& points)
    : mPoints(points) {
}  // 通过点集初始化
CGLineStrip::~CGLineStrip() {}

// 添加点方法
void CGLineStrip::AddPoint(const glm::dvec3& point) {
    mPoints.push_back(point);  // 追加到点集末尾
}

// 序列化方法（保存/加载折线数据）
void CGLineStrip::Serialize(CArchive& ar) {
    CGGeometry::Serialize(ar);  // 先调用基类序列化

    if (ar.IsStoring()) { // 保存模式
        ar << mPoints.size();  // 写入点数量
        for (auto& p : mPoints) // 遍历写入每个点坐标
            ar << p.x << p.y << p.z;
    }
    else { // 加载模式
        size_t size;
        ar >> size;  // 读取点数量
        mPoints.resize(size);
        for (auto& p : mPoints) // 遍历读取每个点坐标
            ar >> p.x >> p.y >> p.z;
    }
}

// 渲染方法（OpenGL绘制）
bool CGLineStrip::Render(CGRenderContext* pRC, CGCamera* pCamera) {
    if (mPoints.size() < 2) return false; // 至少需要2个点

    glColor3f(1.0f, 1.0f, 1.0f);  // 设置白色绘制
    glBegin(GL_LINE_STRIP);       // 开始折线绘制模式
    for (const auto& p : mPoints) // 遍历所有点
        glVertex3d(p.x, p.y, p.z); // 添加顶点
    glEnd();                      // 结束绘制

    return true;
}
void CGLineStrip::Translate(float tx, float ty) {
	// 遍历所有点并应用平移
	for (auto& point : mPoints) {
		point.x += tx; // x 坐标平移
		point.y += ty; // y 坐标平移
		// z 坐标保持不变（如果是 2D 折线）
	}
}

void CGLineStrip::Rotate(double angle, double cx, double cy)
{
	// 如果点列表为空，直接返回
	if (mPoints.empty()) {
		return;
	}

	// 创建变换矩阵
	glm::dmat4 transform(1.0); // 初始化为单位矩阵

	// 1. 平移到原点 (将旋转中心移到原点)
	transform = glm::translate(transform, glm::dvec3(-cx, -cy, 0.0));

	// 2. 绕Z轴旋转 (逆时针为正)
	transform = glm::rotate(transform, glm::radians(angle), glm::dvec3(0.0, 0.0, 1.0));

	// 3. 平移回原位置
	transform = glm::translate(transform, glm::dvec3(cx, cy, 0.0));

	// 应用变换到所有点
	for (auto& point : mPoints) {
		// 将点转换为齐次坐标 (w=1)
		glm::dvec4 transformed = transform * glm::dvec4(point, 1.0);

		// 更新点坐标 (除以w分量，虽然这里w=1不需要除)
		point = glm::dvec3(transformed.x, transformed.y, point.z);
	}
}


void CGLineStrip::Scale(double sx, double sy, double cx, double cy)
{
	// 1. 创建平移矩阵（将中心点移动到原点）
	glm::dmat4 translateToOrigin = glm::translate(glm::dmat4(1.0), glm::dvec3(-cx, -cy, 0.0));

	// 2. 创建缩放矩阵
	glm::dmat4 scaleMatrix = glm::scale(glm::dmat4(1.0), glm::dvec3(sx, sy, 1.0));

	// 3. 创建反向平移矩阵（将中心点移回原位置）
	glm::dmat4 translateBack = glm::translate(glm::dmat4(1.0), glm::dvec3(cx, cy, 0.0));

	// 4. 组合变换矩阵：T⁻¹ * S * T
	glm::dmat4 transformMatrix = translateBack * scaleMatrix * translateToOrigin;

	// 5. 应用变换到所有点
	for (auto& point : mPoints) {
		glm::dvec4 transformedPoint = transformMatrix * glm::dvec4(point, 1.0);
		point = glm::dvec3(transformedPoint);
	}
}