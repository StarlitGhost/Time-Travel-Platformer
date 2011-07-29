#include "GameObject.h"

// Engine Headers
#include "ComponentSystem/GOComponent.h"

using namespace FlatWorld;

GameObject::GameObject(const GOIdType& id)
{
	SetId(id);
}

GameObject::~GameObject(void)
{
	ClearComponents();
}

void GameObject::Update(float dt)
{
	ComponentMap::iterator component = _components.begin();
	for (; component != _components.end(); ++component)
	{
		if (component->second)
			component->second->Update(dt);
		else
			component->second->GetOwner();
	}
}

GOComponent* GameObject::GetComponent(const GOCIdType& familyId)
{
	if (_components[familyId])
	{
		return _components[familyId];
	}
	else
	{
		return NULL;
	}
}

void GameObject::AddComponent(GOComponent* component)
{
	if (_components[component->FamilyId()])
	{
		delete _components[component->FamilyId()];
	}
	component->SetOwner(this);
	_components[component->FamilyId()] = component;
}

void GameObject::RemoveComponent(const GOCIdType& familyId)
{
	if (_components[familyId])
	{
		_components[familyId]->SetOwner(NULL);
		delete _components[familyId];
		_components.erase(familyId);
	}
}

void GameObject::ClearComponents()
{
	for (ComponentMap::iterator component = _components.begin();
		component != _components.end(); ++component)
	{
		delete component->second;
	}
	_components.clear();
}
