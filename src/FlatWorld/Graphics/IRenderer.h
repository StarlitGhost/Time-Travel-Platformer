#pragma once

namespace FlatWorld
{
	class Colour;
	class Rectangle;
	class Transform;
	class Vector2f;

	class IRenderer
	{
	public:
		enum MatrixIdentifier
		{
			MAT_ModelView,
			MAT_Projection,
			MAT_Texture
		};

		enum BlendModes
		{
			BLEND_Transparency,
			BLEND_None
		};

		virtual void Clear() = 0;

		virtual void SetViewport(const FlatWorld::Rectangle& rectangle) = 0;

		virtual void ApplyTexture(unsigned int textureHandle) = 0;
		virtual void SetColour(const Colour& colour) = 0;
		virtual void SetBlendMode(BlendModes whichMode) = 0;

		virtual void SetToIdentityMatrix(MatrixIdentifier whichMatrix = MAT_ModelView) = 0;
		virtual void PushMatrix(MatrixIdentifier whichMatrix = MAT_ModelView) = 0;
		virtual void PopMatrix(MatrixIdentifier whichMatrix = MAT_ModelView) = 0;

		virtual void Translate(const Vector2f& translate) = 0;
		virtual void Rotate(float angle) = 0;
		virtual void Scale(const Vector2f& scale) = 0;
		virtual void Transform(const FlatWorld::Transform& xform) = 0;

		virtual void DrawQuad() = 0;

	};
}
