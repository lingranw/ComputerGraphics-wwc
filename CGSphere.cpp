#include "pch.h"
#include "CGSphere.h"
#include "TessellationHints.h"
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
IMPLEMENT_SERIAL(CGSphere, CGRenderable, 1)
CGSphere::CGSphere(float radius) : mRadius(radius) {}
CGSphere::CGSphere(const CGSphere& sphere)
    : CGRenderable(sphere),
    mRadius(sphere.mRadius),
    mTessellationHints(sphere.mTessellationHints) {
}
void CGSphere::setRadius(float radius) {
    if (mRadius != radius) {
        mRadius = radius;
        setDisplayListDirty(true); // 半径变化时标记显示列表需要更新
    }
}
void CGSphere::setTessellationHints(std::shared_ptr<TessellationHints> hints) {
    if (mTessellationHints.get() != hints.get()) {
        mTessellationHints = hints;
        setDisplayListDirty(true); // 细分数变化时触发显示列表重新编译
    }
}
void CGSphere::buildDisplayList() {
    TessellationHints* hints = tessellationHints();
    bool createNormals = hints ? hints->createNormals() : true;
    bool createTextureCoords = hints ? hints->createTextureCoords() : true;
    // 获取细分参数
    unsigned int slices = hints ? hints->targetSlices() : 40;
    unsigned int stacks = hints ? hints->targetStacks() : 20;
    // 生成球体顶点
    for (unsigned int slice = 0; slice < slices; ++slice) { // 修改为 slice < slices
        float theta1 = slice * glm::two_pi<float>() / slices;    // 当前经度角
        float theta2 = (slice + 1) * glm::two_pi<float>() / slices; // 下一经度角
        glBegin(GL_QUAD_STRIP);
        for (unsigned int stack = 0; stack <= stacks; ++stack) {
            float phi = stack * glm::pi<float>() / stacks;       // 纬度角
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);
            // 顶点 pos1（当前经度）
            glm::vec3 pos1(mRadius * cos(theta1) * sinPhi, mRadius * sin(theta1) * sinPhi, mRadius * cosPhi);
            // 顶点 pos2（下一经度）
            glm::vec3 pos2(mRadius * cos(theta2) * sinPhi, mRadius * sin(theta2) * sinPhi, mRadius * cosPhi);
            // 法线（已归一化）
            if (createNormals) {
                glm::vec3 normal1 = glm::normalize(pos1);
                glNormal3fv(glm::value_ptr(normal1));
            }
            // 纹理坐标（修复 s2 和 t 的范围）
            if (createTextureCoords) {
                float s1 = static_cast<float>(slice) / slices;   // s ∈ [0, 1)
                float s2 = static_cast<float>(slice + 1) / slices; // s ∈ (0, 1]
                float t = static_cast<float>(stack) / stacks;    // t ∈ [0, 1]
                glTexCoord2f(s1, t);
                glVertex3fv(glm::value_ptr(pos1));
                glTexCoord2f(s2, t); // s2 和 t 已正确初始化
                glVertex3fv(glm::value_ptr(pos2));
            }
            else {
                glVertex3fv(glm::value_ptr(pos1));
                glVertex3fv(glm::value_ptr(pos2));
            }
        }
        glEnd();
    }
}
