#include "Cube.h"



Cube::Cube(Renderer * rendererPtr) : Mesh(rendererPtr)
{
	vertexCount = 3;

	g_vertex_buffer_data = new float[vertexCount * 36]
	{
		-50.0f,-50.0f,-50.0f, // triangle 1 : begin
		-50.0f,-50.0f, 50.0f,
		-50.0f, 50.0f, 50.0f, // triangle 1 : end
		50.0f, 50.0f,-50.0f, // triangle 2 : begin
		-50.0f,-50.0f,-50.0f,
		-50.0f, 50.0f,-50.0f, // triangle 2 : end
		50.0f,-50.0f, 50.0f,
		-50.0f,-50.0f,-50.0f,
		50.0f,-50.0f,-50.0f,
		50.0f, 50.0f,-50.0f,
		50.0f,-50.0f,-50.0f,
		-50.0f,-50.0f,-50.0f,
		-50.0f,-50.0f,-50.0f,
		-50.0f, 50.0f, 50.0f,
		-50.0f, 50.0f,-50.0f,
		50.0f,-50.0f, 50.0f,
		-50.0f,-50.0f, 50.0f,
		-50.0f,-50.0f,-50.0f,
		-50.0f, 50.0f, 50.0f,
		-50.0f,-50.0f, 50.0f,
		50.0f,-50.0f, 50.0f,
		50.0f, 50.0f, 50.0f,
		50.0f,-50.0f,-50.0f,
		50.0f, 50.0f,-50.0f,
		50.0f,-50.0f,-50.0f,
		50.0f, 50.0f, 50.0f,
		50.0f,-50.0f, 50.0f,
		50.0f, 50.0f, 50.0f,
		50.0f, 50.0f,-50.0f,
		-50.0f, 1.0f,-50.0f,
		50.0f, 50.0f, 50.0f,
		-50.0f, 50.0f,-50.0f,
		-50.0f, 50.0f, 50.0f,
		50.0f, 50.0f, 50.0f,
		-50.0f, 50.0f, 50.0f,
		50.0f,-50.0f, 50.0f
	};

	indices = new unsigned int [vertexCount * 12]
	{
		0, 1, 2,
		3, 1, 2,
		1, 4, 0,
		5, 4, 0,
		1, 4, 3,
		6, 4, 3,
		5, 0, 7,
		2, 0, 7,
		2, 3, 7,
		6, 3, 7,
		5, 4, 7,
		6, 4, 7
	};
}


Cube::~Cube()
{
}
