#include "GOTemplate.h"

#include "GOCTemplate.h"

using namespace FlatWorld;

GOTemplate::GOTemplate(const std::string& name)
{
	_name = name;
}

GOTemplate::~GOTemplate()
{
	Clear();
}

void GOTemplate::Clear()
{
	for (GOCTListType::iterator goct = _components.begin(); goct != _components.end(); ++goct)
	{
		delete *goct;
	}
}

void GOTemplate::AddGOCTemplate(GOCTemplate* gocTemplate)
{
	_components.push_back(gocTemplate);
}

GOCTemplate* GOTemplate::GetGOCTemplate(const GOCIdType& id) const
{
	GOCTListType::const_iterator goct = _components.begin();
	for (; goct != _components.end(); ++goct)
	{
		if ((*goct)->ComponentId() == id)
			break;
	}

	if (goct == _components.end())
		return NULL;

	return *goct;
}
