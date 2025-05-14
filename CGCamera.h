#pragma once 
#include "CGTransform.h" 
class CGCamera : public CGTransform
{
	DECLARE_SERIAL(CGCamera)
public:
	CGCamera();
	virtual ~CGCamera();
	//���л� 
	virtual void Serialize(CArchive& ar) override;

	//mode=0Ϊ����ͶӰ����ά����mode=1Ϊ͸��ͶӰ��mode=2������Ϊ����ͶӰ����ά�� 
	virtual void Projection(int mode);


	int ProjectionMode() { return mProjectionMode; }
	void SetProjectionMode(int mode) { if (mode >= 0 && mode <= 2) mProjectionMode = mode; }

protected:
	int mProjectionMode = 0;
};