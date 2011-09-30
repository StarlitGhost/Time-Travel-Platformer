#include "RendererGL.h"

#include <SFML/OpenGL.hpp>

#include "Graphics/Colour.h"
#include "Maths/Rectangle.h"
#include "Maths/Transform.h"

using namespace FlatWorld;

void RendererGL::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererGL::SetViewport(const FlatWorld::Rectangle& rectangle)
{
	Vector2f botLeft = rectangle.BottomLeft();
	int width = (int)rectangle.Width(), height = (int)rectangle.Height();

	glViewport((int)botLeft.x, (int)botLeft.y, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(botLeft.x, width, botLeft.y, height);
	glMatrixMode(GL_MODELVIEW);
}

void RendererGL::ApplyTexture(unsigned int textureHandle)
{
	glBindTexture(GL_TEXTURE_2D, textureHandle);
}

void RendererGL::SetColour(const Colour& colour)
{
	glColor4fv(colour.RGBA());
}

void RendererGL::SetBlendMode(BlendModes mode)
{
	switch (mode)
	{
	case BLEND_Transparency:
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BLEND_None:
		glDisable(GL_BLEND);
		break;
	}
}

void RendererGL::SetToIdentityMatrix(MatrixIdentifier /*whichMatrix /*= MAT_ModelView*/)
{
	glLoadIdentity();
}

void RendererGL::PushMatrix(MatrixIdentifier /*whichMatrix /*= MAT_ModelView*/)
{
	glPushMatrix();
}

void RendererGL::PopMatrix(MatrixIdentifier /*whichMatrix /*= MAT_ModelView*/)
{
	glPopMatrix();
}

void RendererGL::Translate(const Vector2f& translate)
{
	glTranslatef(translate.x, translate.y, 0.f);
}

void RendererGL::Rotate(float angle)
{
	glRotatef(angle, 0.f, 0.f, 1.f);
}

void RendererGL::Scale(const Vector2f& scale)
{
	glScalef(scale.x, scale.y, 1.f);
}

void RendererGL::Transform(const FlatWorld::Transform& xform)
{
	Translate(xform.Position);
	Rotate(xform.Angle);
	Scale(xform.Scale);
}

void RendererGL::DrawQuad()
{
	static const GLfloat vertices[] = 
	{
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f
	};

	static const GLfloat texCoords[] =
	{
		0.f, 0.f,
		1.f, 0.f,
		1.f, 1.f,
		0.f, 1.f
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
