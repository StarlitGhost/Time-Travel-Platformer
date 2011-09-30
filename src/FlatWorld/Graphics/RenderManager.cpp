#include "RenderManager.h"

using namespace FlatWorld;

IRenderer* RenderManager::_renderer = 0;

void RenderManager::Clear()
{
	_renderer->Clear();
}

void RenderManager::SetViewport(const FlatWorld::Rectangle& rectangle)
{
	_renderer->SetViewport(rectangle);
}

void RenderManager::SetRenderer(IRenderer* renderer)
{
	_renderer = renderer;
}

void RenderManager::ApplyTexture(unsigned int textureHandle)
{
	_renderer->ApplyTexture(textureHandle);
}

void RenderManager::SetColour(const Colour& colour)
{
	_renderer->SetColour(colour);
}

void RenderManager::SetBlendMode(IRenderer::BlendModes whichMode)
{
	_renderer->SetBlendMode(whichMode);
}

void RenderManager::SetToIdentityMatrix(IRenderer::MatrixIdentifier whichMatrix /*= IRenderer::MAT_ModelView*/)
{
	_renderer->SetToIdentityMatrix(whichMatrix);
}

void RenderManager::PushMatrix(IRenderer::MatrixIdentifier whichMatrix /*= IRenderer::MAT_ModelView*/)
{
	_renderer->PushMatrix(whichMatrix);
}

void RenderManager::PopMatrix(IRenderer::MatrixIdentifier whichMatrix /*= IRenderer::MAT_ModelView*/)
{
	_renderer->PopMatrix(whichMatrix);
}

void RenderManager::Translate(const Vector2f& translate)
{
	_renderer->Translate(translate);
}

void RenderManager::Rotate(float angle)
{
	_renderer->Rotate(angle);
}

void RenderManager::Scale(const Vector2f& scale)
{
	_renderer->Scale(scale);
}

void RenderManager::Transform(const FlatWorld::Transform& xform)
{
	_renderer->Transform(xform);
}

void RenderManager::DrawQuad()
{
	_renderer->DrawQuad();
}
