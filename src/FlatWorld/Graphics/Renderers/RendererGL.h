#pragma once

#include "Graphics/IRenderer.h"

namespace FlatWorld
{
	class RendererGL : public IRenderer
	{
	public:
		virtual void Clear();

		virtual void SetViewport(const FlatWorld::Rectangle& rectangle);

		virtual void ApplyTexture(unsigned int textureHandle);
		virtual void SetColour(const Colour& colour);
		virtual void SetBlendMode(BlendModes mode);

		virtual void SetToIdentityMatrix(MatrixIdentifier whichMatrix = MAT_ModelView);
		virtual void PushMatrix(MatrixIdentifier whichMatrix = MAT_ModelView);
		virtual void PopMatrix(MatrixIdentifier whichMatrix = MAT_ModelView);

		virtual void Translate(const Vector2f& translate);
		virtual void Rotate(float angle);
		virtual void Scale(const Vector2f& scale);
		virtual void Transform(const FlatWorld::Transform& xform);

		virtual void DrawQuad();

	};
}
