#pragma once

#include "Graphics/IRenderer.h"

namespace FlatWorld
{
	class Colour;
	class Transform;

	class RenderManager
	{
	public:
		static void SetRenderer(IRenderer* _renderer);

		static void Clear();

		static void SetViewport(const FlatWorld::Rectangle& rectangle);

		static void ApplyTexture(unsigned int textureHandle);
		static void SetColour(const Colour& colour);
		static void SetBlendMode(IRenderer::BlendModes whichMode);

		static void SetToIdentityMatrix(IRenderer::MatrixIdentifier whichMatrix = IRenderer::MAT_ModelView);
		static void PushMatrix(IRenderer::MatrixIdentifier whichMatrix = IRenderer::MAT_ModelView);
		static void PopMatrix(IRenderer::MatrixIdentifier whichMatrix = IRenderer::MAT_ModelView);

		static void Translate(const Vector2f& translate);
		static void Rotate(float angle);
		static void Scale(const Vector2f& scale);
		static void Transform(const FlatWorld::Transform& xform);

		static void DrawQuad();

	private:
		static IRenderer* _renderer;

	};
}
