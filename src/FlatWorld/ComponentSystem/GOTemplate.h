#pragma once

#include <vector>

#include "ComponentSystem/typedefs.h"

namespace FlatWorld
{
	class GOCTemplate;

	class GOTemplate
	{
	public:
		typedef std::vector<GOCTemplate*> GOCTListType;

		GOTemplate(const std::string& name);
		~GOTemplate();

		void Clear();

		const std::string& GetName() const { return _name; }
		void SetName(const std::string& name) { _name = name; }

		GOCTListType& Components() { return _components; }

		void AddGOCTemplate(GOCTemplate* gocTemplate);
		GOCTemplate* GetGOCTemplate(const GOCIdType& id) const;

	protected:
		std::string _name;
		GOCTListType _components;

	};
}
