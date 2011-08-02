#include "GOTManager.h"

#include "ComponentSystem/GameObject.h"
#include "ComponentSystem/GOCTemplate.h"

using namespace FlatWorld;

GOTManager* GOTManager::Instance()
{
	if (!_instance)
		_instance = new GOTManager();

	return _instance;
}

void GOTManager::RegisterTemplate(GOTemplate* goTemplate)
{
	_templateMap[goTemplate->GetName()] = goTemplate;
}

void GOTManager::ClearTemplates()
{
	for (TemplateMap::iterator goct = _templateMap.begin(); goct != _templateMap.end(); ++goct)
	{
		goct->second->Clear();
		delete goct->second;
	}
}

GameObject* GOTManager::CreateGO(std::string templateName, GOCIdType& goID)
{
	if (_templateMap.find(templateName) == _templateMap.end())
		return NULL;

	GameObject* go = new GameObject(goID);
	GOTemplate::GOCTListType components = _templateMap[templateName]->Components();

	for (GOTemplate::GOCTListType::iterator goc = components.begin(); goc != components.end(); ++goc)
	{
		go->AddComponent((*goc)->MakeComponent());
	}

	return go;
}
