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
        setDisplayListDirty(true); // �뾶�仯ʱ�����ʾ�б���Ҫ����
    }
}
void CGSphere::setTessellationHints(std::shared_ptr<TessellationHints> hints) {
    if (mTessellationHints.get() != hints.get()) {
        mTessellationHints = hints;
        setDisplayListDirty(true); // ϸ�����仯ʱ������ʾ�б����±���
    }
}
void CGSphere::buildDisplayList() {
    TessellationHints* hints = tessellationHints();
    bool createNormals = hints ? hints->createNormals() : true;
    bool createTextureCoords = hints ? hints->createTextureCoords() : true;
    // ��ȡϸ�ֲ���
    unsigned int slices = hints ? hints->targetSlices() : 40;
    unsigned int stacks = hints ? hints->targetStacks() : 20;
    // �������嶥��
    for (unsigned int slice = 0; slice < slices; ++slice) { // �޸�Ϊ slice < slices
        float theta1 = slice * glm::two_pi<float>() / slices;    // ��ǰ���Ƚ�
        float theta2 = (slice + 1) * glm::two_pi<float>() / slices; // ��һ���Ƚ�
        glBegin(GL_QUAD_STRIP);
        for (unsigned int stack = 0; stack <= stacks; ++stack) {
            float phi = stack * glm::pi<float>() / stacks;       // γ�Ƚ�
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);
            // ���� pos1����ǰ���ȣ�
            glm::vec3 pos1(mRadius * cos(theta1) * sinPhi, mRadius * sin(theta1) * sinPhi, mRadius * cosPhi);
            // ���� pos2����һ���ȣ�
            glm::vec3 pos2(mRadius * cos(theta2) * sinPhi, mRadius * sin(theta2) * sinPhi, mRadius * cosPhi);
            // ���ߣ��ѹ�һ����
            if (createNormals) {
                glm::vec3 normal1 = glm::normalize(pos1);
                glNormal3fv(glm::value_ptr(normal1));
            }
            // �������꣨�޸� s2 �� t �ķ�Χ��
            if (createTextureCoords) {
                float s1 = static_cast<float>(slice) / slices;   // s �� [0, 1)
                float s2 = static_cast<float>(slice + 1) / slices; // s �� (0, 1]
                float t = static_cast<float>(stack) / stacks;    // t �� [0, 1]
                glTexCoord2f(s1, t);
                glVertex3fv(glm::value_ptr(pos1));
                glTexCoord2f(s2, t); // s2 �� t ����ȷ��ʼ��
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
