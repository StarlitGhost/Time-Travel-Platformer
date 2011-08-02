#pragma once

#include <map>

#include "ComponentSystem/GOTemplate.h"

namespace FlatWorld
{
	class GameObject;

	class GOTManager
	{
	public:
		static GOTManager* Instance();

		~GOTManager() {}

		void RegisterTemplate(GOTemplate* goTemplate);
		void ClearTemplates();

		GameObject* CreateGO(std::string templateName, GOCIdType& goID);

	protected:
		GOTManager() {}

		static GOTManager* _instance;

		typedef std::map<std::string, GOTemplate*> TemplateMap;
		TemplateMap _templateMap;

	};
}
