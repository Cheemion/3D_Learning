#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx10math.h>
#include "textureclass.h"
#include <fstream>
using namespace std;
class ModelClass
{
private:	
	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;

	};

public:
	bool Initialize(ID3D11Device*, char*, WCHAR*);
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();
	void Shutdown();
	void Render(ID3D11DeviceContext*);
	ID3D11ShaderResourceView* GetTexture();

	int GetIndexCount();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);
	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();
	bool LoadModel(char*);
	void ReleaseModel();
private:
	TextureClass* m_Texture;
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	int m_vertexCount, m_indexCount;
	ModelType* m_model;

};

#endif

