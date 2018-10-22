#include "Texture.h"
#include "BMPLoader.h"
#include <glew.h>
#include "GLFW\glfw3.h"

Texture::Texture(Renderer * rendererPtr, const char * imagepath) : Shape(rendererPtr)
{
	texture = BMPLoader::LoadBMP(imagepath);
	vertexCount = 4;

	g_vertex_buffer_data = new float[vertexCount * 3]
	{
		-1.0f,1.0f, 0.0f,
		1.0f,1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f,0.0f,
	};

	g_uv_buffer_data = new float[vertexCount*2]
	{
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
	};

	vertexBuffer = renderer->GenBuffer(sizeof(float)*vertexCount * 3, g_vertex_buffer_data);
	uvBuffer = renderer->GenUVBuffer(sizeof(float)*vertexCount*2, g_uv_buffer_data);
}


Texture::~Texture()
{
	renderer->DestroyBuffer(vertexBuffer);
	renderer->DestroyBuffer(uvBuffer);
	delete[] g_vertex_buffer_data;
	delete[] g_uv_buffer_data;
}

void Texture::Draw()
{
	renderer->LoadIdentityMatrix();
	renderer->SetModelMatrix(model);

	if (material != nullptr)
	{
		material->Bind();
		material->SetMatrixProperty(renderer->GetMVP());
		material->SetTextureProperty();
	}

	renderer->BindTexture(texture);
	renderer->EnableAttributes(0);
	renderer->EnableAttributes(1);
	renderer->BindBuffer(vertexBuffer, 0);
	renderer->BindColorBuffer(uvBuffer, 1);
	renderer->DrawBuffer(vertexCount);
}