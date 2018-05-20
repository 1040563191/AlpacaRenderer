/*******************************************************************
 * \file Mesh.h
 *
 * \author puppet_master
 * \date 2018/05/20���ע��
 * \https://blog.csdn.net/puppet_master
 * \Mesh�࣬��װ������������Mesh�������Σ������Σ������壬
 * \���Ը���Vertex��Index����
 *******************************************************************/
#pragma once
#include "Vertex.h"
#include "ApcDevice.h"
#include <vector>

class Mesh
{
private:
	std::vector<Vertex> vertexBuffer;
	std::vector<int> indexBuffer;

	void DrawElement(ApcDevice* device);
	void DrawArray(ApcDevice* device);
public:
	Mesh();
	~Mesh();

	static Mesh* CreateTrangle();
	static Mesh* CreatePlane();
	static Mesh* CreateCube();

	void AddVertexData(const Vector3 & pos, float u, float v, const Color& color = Color::white);
	void AddVertexData(float posx, float posy, float posz, float u, float v, const Color& color = Color::white);

	void DrawMesh(ApcDevice* device);
};

