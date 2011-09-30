#include "gocVisualRectangle.h"

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/Maths/Vector2f.h"
#include "FlatWorld/Graphics/RenderManager.h"

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
		RenderManager::DrawQuad();
	}
	RenderManager::PopMatrix();

}
