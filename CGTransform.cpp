#include "pch.h" 
#include "CGTransform.h" 

IMPLEMENT_SERIAL(CGTransform, CGGroup, 1)

CGTransform::CGTransform()
{
}

CGTransform::~CGTransform()
{
}
void CGTransform::Serialize(CArchive& ar)
{
    CGGroup::Serialize(ar); //�ȵ��û�������л������������л��Լ��ĳ�Ա��������Ҫ�� 
    if (ar.IsStoring())  //���� 
    {
        //ar << ; //����������Ҫ��������ݳ�Ա��<<�����֧�ֵ����Ͳ���CArchiveʹ��˵�� 
    }
    else //��ȡ 
    {
        //ar >> ;
    }
}

bool CGTransform::Render(CGRenderContext* pRC, CGCamera* pCamera)
{
    if (pRC == nullptr || pCamera == nullptr)
        return false;

    glPushMatrix(); //���� 
    glMultMatrixf(glm::value_ptr(localMatrix())); //�����һ���任 
    if (getRenderStateSet()) {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        getRenderStateSet()->apply(pCamera, pRC);
    }
    for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
    {
        (*itr)->Render(pRC, pCamera);
    }
    if (getRenderStateSet()) {
        glPopAttrib();
    }
    glPopMatrix();  //�ָ� 

    return true;
}

void CGTransform::dirtyWorldMatrix()
{
    mWorldMatrixDirty = true;
    for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
    {
        CGTransform* trans = (*itr != nullptr) ? (*itr)->asTransform() : 0;
        if (trans) {
            trans->dirtyWorldMatrix();
        }
    }
    dirtyBound();
}
void CGTransform::setLocalMatrix(const glm::mat4& m)
{
    mLocalMatrix = m;
    dirtyWorldMatrix(); //�ֲ�����仯�ᵼ�µ���������ϵ�ľ���ı䡣 
}
void CGTransform::translate(float tx, float ty, float tz)
{
	mLocalMatrix = glm::translate(mLocalMatrix, glm::vec3(tx, ty, tz));
    dirtyWorldMatrix();
}
void CGTransform::translate(const glm::vec3& t)
{
	mLocalMatrix = glm::translate(mLocalMatrix, t);
	dirtyWorldMatrix();
}
void CGTransform::scale(float sx, float sy, float sz)
{
	mLocalMatrix = glm::scale(mLocalMatrix, glm::vec3(sx, sy, sz));
    dirtyWorldMatrix();
}
void CGTransform::rotate(float degrees, float x, float y, float z)
{
	mLocalMatrix = glm::rotate(mLocalMatrix, glm::radians(degrees), glm::vec3(x, y, z));
    dirtyWorldMatrix();
}
void CGTransform::preMultiply(const glm::mat4& m)
{
	mLocalMatrix = m * mLocalMatrix; //��˾���m
    dirtyWorldMatrix();
}
void CGTransform::postMultiply(const glm::mat4& m)
{
	mLocalMatrix = mLocalMatrix * m; //�ҳ˾���m
    dirtyWorldMatrix();
}