#include "GOTemplate.h"

#include "GOCTemplate.h"

using namespace FlatWorld;

GOTemplate::GOTemplate(const std::string& name)
{

}

GOTemplate::~GOTemplate()
{
	Clear();
}

void GOTemplate::Clear()
{

}

void GOTemplate::AddGOCTemplate(const GOCTemplate* gocTemplate)
{
	_components.push_back(gocTemplate);
}

GOCTemplate* FlatWorld::GOTemplate::GetGOCTemplate(const GOCIdType& id) const
{

}
