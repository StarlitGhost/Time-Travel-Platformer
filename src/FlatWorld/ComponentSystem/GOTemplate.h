#pragma once

#include <list>

#include "typedefs.h"

namespace FlatWorld
{
	class GOCTemplate;

	class GOTemplate
	{
	public:
		typedef std::list<const GOCTemplate*> GOCTListType;

		~GOTemplate();

		void Clear();

		const std::string& GetName() const { return _name; }
		void SetName(const std::string& name) { _name = name; }

		GOCTListType& Components() { return _components; }

		void AddGOCTemplate(const GOCTemplate* gocTemplate);
		GOCTemplate* GetGOCTemplate(const GOCIdType& id) const;

	protected:
		GOTemplate(const std::string& name);
		std::string _name;
		GOCTListType _components;

	};
}
