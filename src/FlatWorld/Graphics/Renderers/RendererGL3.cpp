#include "RendererGL3.h"

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "Graphics/Colour.h"
#include "Maths/Rectangle.h"
#include "Maths/Transform.h"

using namespace FlatWorld;

void RendererGL3::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererGL3::SetViewport(const FlatWorld::Rectangle& rectangle)
{
	Vector2f botLeft = rectangle.BottomLeft();
	int width = (int)rectangle.Width(), height = (int)rectangle.Height();

	glViewport((int)botLeft.x, (int)botLeft.y, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(botLeft.x, width, botLeft.y, height);
	glMatrixMode(GL_MODELVIEW);
}

void RendererGL3::ApplyTexture(unsigned int textureHandle)
{
	glBindTexture(GL_TEXTURE_2D, textureHandle);
}

void RendererGL3::SetColour(const Colour& colour)
{
	glColor4fv(colour.RGBA());
}

void RendererGL3::SetBlendMode(BlendModes mode)
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

void RendererGL3::SetToIdentityMatrix(MatrixIdentifier /*whichMatrix /*= MAT_ModelView*/)
{
	glLoadIdentity();
}

void RendererGL3::PushMatrix(MatrixIdentifier /*whichMatrix /*= MAT_ModelView*/)
{
	glPushMatrix();
}

void RendererGL3::PopMatrix(MatrixIdentifier /*whichMatrix /*= MAT_ModelView*/)
{
	glPopMatrix();
}

void RendererGL3::Translate(const Vector2f& translate)
{
	glTranslatef(translate.x, translate.y, 0.f);
}

void RendererGL3::Rotate(float angle)
{
	glRotatef(angle, 0.f, 0.f, 1.f);
}

void RendererGL3::Scale(const Vector2f& scale)
{
	glScalef(scale.x, scale.y, 1.f);
}

void RendererGL3::Transform(const FlatWorld::Transform& xform)
{
	Translate(xform.Position);
	Rotate(xform.Angle);
	Scale(xform.Scale);
}

void RendererGL3::DrawQuad()
{
	_basicShader.Bind();

	glBindBuffer(GL_ARRAY_BUFFER, _quadVBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glDisableVertexAttribArray(0);

	_basicShader.Unbind();

	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void RendererGL3::initVBO()
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

	glGenBuffers(1, &_quadVBO);

	glBindBuffer(GL_ARRAY_BUFFER, _quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

RendererGL3::RendererGL3()
{
	initVBO();
	_basicShader.Init("basic.vert", "basic.frag");
}
