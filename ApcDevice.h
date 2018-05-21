/*******************************************************************
 * \file ApcDevice.h
 *
 * \author puppet_master
 * \date 2018/05/20���ע��
 * \https://blog.csdn.net/puppet_master
 * \��������Ⱦ��AlpacaSoftRenderer����Ҫʵ��
 * \����MVP�������ɣ��ӿ�ӳ�䣬�򵥲ü�����Ȳ��ԣ���դ�������ݲ�ֵ
 * \�������ֲ��Ժ�����������2D����
 *******************************************************************/
#pragma once
#include "Stdfx.h"
#include "Matrix.h"
#include "Vertex.h"
#include "Texture.h"
class ApcDevice
{
private:
	int deviceWidth;
	int deviceHeight;
	HDC screenHDC;
	Texture* tex;
	float** zBuffer;

public:
	ApcDevice();
	~ApcDevice();

	void InitDevice(HDC hdc, int screenWidth, int screenHeight);
	void ReleaseDevice();
	void Clear();

	void DrawPrimitive(Vertex v1, Vertex v2, Vertex v3, const Matrix& mvp);
	void RasterizeTrangle(Vertex v1, Vertex v2, Vertex v3);
	void DrawTopFlatTrangle(Vertex v1, Vertex v2, Vertex v3);
	void DrawBottomFlatTrangle(Vertex v1, Vertex v2, Vertex v3);
	void DrawLine(Vertex v1, Vertex v2);
	void DrawPixel(int x, int y, const Color& color);

	Matrix GenMVPMatrix();
	Matrix GenTranslateMatrix(const Vector3& v);
	Matrix GenScaleMatrix(const Vector3& v);
	Matrix GenRotationMatrix(const Vector3& rotAngle);
	Matrix GenRotationXMatrix(float angle);
	Matrix GenRotationYMatrix(float angle);
	Matrix GenRotationZMatrix(float angle);
	Matrix GenCameraMatrix(const Vector3& eyePos, const Vector3& lookPos, const Vector3& upAxis);
	Matrix GenProjectionMatrix(float fov, float aspect, float nearPanel, float farPanel);

	bool ZTestAndWrite(int x, int y, float depth);
	//��CVV�޳���ֻ��������������ڵ������δ���߽����������¹���
	bool SimpleCVVCullCheck(const Vertex& vertex);
	//׼����դ����͸��ͶӰ�������ӿ�ӳ�䣬����������׼��
	void PrepareRasterization(Vertex& vertex);

	//����Ϊ���Թ�դ�������������Ļ��ߣ��������Σ����������������ݵĻ���
	void DrawTrangle3D(const Vector3& v1, const Vector3& v2, const Vector3& v3, const Matrix& mvp);
	void DrawTrangle(int x0, int y0, int x1, int y1, int x2, int y2);
	void DrawTopFlatTrangle(int x0, int y0, int x1, int y1, int x2, int y2);
	void DrawBottomFlatTrangle(int x0, int y0, int x1, int y1, int x2, int y2);
	void DrawLine(int x0, int y0, int x1, int y1);
	void DrawPixel(int x, int y);
	Vector3 GetScreenCoord(const Vector3& v);
	
};

