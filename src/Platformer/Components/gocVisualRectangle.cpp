#include "gocVisualRectangle.h"

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/Maths/Vector2f.h"
#include "FlatWorld/Graphics/RenderManager.h"
#include "FlatWorld/Graphics/TextureManager.h"

using namespace FlatWorld;

void gocVisualRectangle::Draw() const
{
	static const float vertices[] = 
	{
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f
	};

	static const float texCoords[] =
	{
		0.f, 0.f,
		1.f, 0.f,
		1.f, 1.f,
		0.f, 1.f
	};

	RenderManager::PushMatrix();
	{
		RenderManager::Transform(GetOwner()->GetTransform());
		RenderManager::ApplyTexture(_textureHandle);
		RenderManager::DrawQuad();
	}
	RenderManager::PopMatrix();
}

void gocVisualRectangle::SetTexture(std::string fileName)
{
	_textureHandle = TextureManager::GetTextureHandle(fileName);
}

unsigned int gocVisualRectangle::GetTexture()
{
	return _textureHandle;
}
