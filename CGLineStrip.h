#pragma once
#include "CGGeometry.h"
#include <vector>

// ���߼������ࣨ�̳���CGGeometry��
class CGLineStrip : public CGGeometry
{
    DECLARE_SERIAL(CGLineStrip)
public:
    CGLineStrip();  
    CGLineStrip(const std::vector<glm::dvec3>& points);
    virtual ~CGLineStrip();

    // ���ܷ���
    void AddPoint(const glm::dvec3& point); // ��̬��ӵ�
    virtual void Serialize(CArchive& ar) override; // ���л���д
    virtual bool Render(CGRenderContext* pRC, CGCamera* pCamera) override; // ��Ⱦ��д
    void Translate(float tx, float ty); //ƽ��

    virtual void Rotate(double angle, double cx, double cy);

    virtual void Scale(double sx, double sy, double cx, double cy);
protected:
    std::vector<glm::dvec3> mPoints; // �洢���ߵ㼯������
};
