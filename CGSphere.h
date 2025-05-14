#pragma once
#include "CGRenderable.h"
#include "TessellationHints.h"
class CGSphere : public CGRenderable
{
    DECLARE_SERIAL(CGSphere)
public:
    CGSphere(float radius = 1.0f);
    CGSphere(const CGSphere& sphere);
    virtual ~CGSphere() {}
    void setRadius(float radius);
    float getRadius() const { return mRadius; }
    void setTessellationHints(std::shared_ptr<TessellationHints> hints);
    TessellationHints* tessellationHints() { return mTessellationHints.get(); }
    const TessellationHints* tessellationHints() const { return mTessellationHints.get(); }
protected:
    virtual void buildDisplayList() override; // 重写显示列表构建函数
protected:
    float mRadius; // 球体半径
    std::shared_ptr<TessellationHints> mTessellationHints = nullptr;
};
