#include "pch.h" 
#include "CGCamera.h" 

IMPLEMENT_SERIAL(CGCamera, CGTransform, 1)

CGCamera::CGCamera()
{
}
CGCamera::~CGCamera()
{
}
void CGCamera::Serialize(CArchive& ar)
{
	CGTransform::Serialize(ar); //�ȵ��û�������л������������л��Լ��ĳ�Ա��������Ҫ�� 
	if (ar.IsStoring())  //���� 
	{
		//ar << ; //����������Ҫ��������ݳ�Ա��<<�����֧�ֵ����Ͳ���CArchiveʹ��˵�� 
	}
	else //��ȡ 
	{
		//ar >> ; 
	}
}

void CGCamera::Projection(int mode)
{
	//������ʵ��ͶӰ���� 
}