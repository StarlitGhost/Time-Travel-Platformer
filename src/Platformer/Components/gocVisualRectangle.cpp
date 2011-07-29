#include "gocVisualRectangle.h"

#include <SFML/Window.hpp>

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/Maths/Vector2f.h"

using namespace FlatWorld;

void gocVisualRectangle::Draw() const
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

	glPushMatrix();
	{
		Transform xform = GetOwner()->GetTransform();

		glTranslatef(xform.Position.x, xform.Position.y, 0.f);
		glRotatef(xform.Angle, 0.f, 0.f, 1.f);
		glScalef(xform.Scale.x, xform.Scale.y, 1.f);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
