#pragma once
#include "CGGeometry.h"
#include <vector>

// 折线几何体类（继承自CGGeometry）
class CGLineStrip : public CGGeometry
{
    DECLARE_SERIAL(CGLineStrip)
public:
    CGLineStrip();  
    CGLineStrip(const std::vector<glm::dvec3>& points);
    virtual ~CGLineStrip();

    // 功能方法
    void AddPoint(const glm::dvec3& point); // 动态添加点
    virtual void Serialize(CArchive& ar) override; // 序列化重写
    virtual bool Render(CGRenderContext* pRC, CGCamera* pCamera) override; // 渲染重写
    void Translate(float tx, float ty); //平移

    virtual void Rotate(double angle, double cx, double cy);

    virtual void Scale(double sx, double sy, double cx, double cy);
protected:
    std::vector<glm::dvec3> mPoints; // 存储折线点集的容器
};
