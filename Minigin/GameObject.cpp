#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include "TextureComponent.h"
#include <iostream>
#include "Font.h"
#include "glm/glm.hpp"
#include "Component.h"
#include <algorithm>


dae::GameObject::GameObject()
	: m_pParentGameObject{nullptr}
{
}

dae::GameObject::~GameObject()
{
	for (GameObject* go : m_pVectorChildren)
	{
		go = nullptr;
	}
	m_pParentGameObject = nullptr;
}

void dae::GameObject::Update(float deltaTime)
{
	//update self
	for (std::shared_ptr<dae::Component> component : m_pVectorComponents)
	{
		component->Update(deltaTime);
	}
	//update children
	for (dae::GameObject* go : m_pVectorChildren)
	{
		go->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float fixedTime)
{
	//update self
	for (std::shared_ptr<dae::Component> component : m_pVectorComponents)
	{
		component->FixedUpdate(fixedTime);
	}
	//update children
	for (dae::GameObject* go : m_pVectorChildren)
	{
		go->FixedUpdate(fixedTime);
	}
}

//CAN ADD A FIXED UPDATE, NOT NECESSARY YET
void dae::GameObject::Render() const
{
	for (std::shared_ptr<dae::Component> component : m_pVectorComponents)
	{
		component->Render();
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	GetComponent<TextureComponent>()->SetTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	GetComponent<Transform>()->SetLocalPosition(x, y);
	SetPositionDirty(); // this will be the second time the transform of this component will be set to true, but it doesn't really matter, its here mostly to change the childrens pos to dirty
}

void dae::GameObject::SetParent(GameObject* parent, bool keepWorldPosition)
{
	//Transform* transformComp{ GetComponent<Transform>() }; //making a temporary one so we don't have to do .GetComponent all the time, gets messy
	//1. Set the Location
	if (m_pParentGameObject == nullptr)
	{
		GetComponent<Transform>()->SetLocalPosition(GetComponent<Transform>()->GetWorldPosition());
	}
	else
	{
		if (keepWorldPosition)
		{
			GetComponent<Transform>()->SetLocalPosition(GetComponent<Transform>()->GetLocalPosition() - m_pParentGameObject->GetComponent<Transform>()->GetWorldPosition());
		}
		SetPositionDirty();
	}

	//2. Remove this child from parent
	if (m_pParentGameObject)
	{
		m_pParentGameObject->RemoveChild(this);
	}
	
	//3. Set new parent as this childs parent
	m_pParentGameObject = parent;

	//4. Add this child to parents list of children
	if (m_pParentGameObject)
	{
		m_pParentGameObject->AddChild(this);
	}
	//transformComp = nullptr; //Clean up for the temporary transformComp, check if this is defined at the start of this SetParent function
}

bool dae::GameObject::HasParent()
{
		return (m_pParentGameObject != nullptr);
}

void dae::GameObject::SetPositionDirty()
{
	GetComponent<Transform>()->SetDirty();
	for (GameObject* go : m_pVectorChildren)
	{
		go->SetPositionDirty();
	}
}

void dae::GameObject::AddChild(GameObject* childGameObj)
{
	m_pVectorChildren.push_back(childGameObj);
}

void dae::GameObject::RemoveChild(GameObject* childGameObj)
{
	const auto childToBeDeletedIterator = std::find(m_pVectorChildren.begin(), m_pVectorChildren.end(), childGameObj);
	if (childToBeDeletedIterator != m_pVectorChildren.end())
	{
		m_pVectorChildren.erase(childToBeDeletedIterator); //needs to be removed from the scene!
	}
	
}

