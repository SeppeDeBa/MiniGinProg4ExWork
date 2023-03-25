#include "Scene.h"
#include "GameObject.h"
#include "TextObject.h"
using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene()
{
	RemoveAll();
}

void Scene::Add(std::shared_ptr<GameObject> object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::Add(std::shared_ptr<TextObject> object)
{
	m_textObjects.emplace_back(std::move(object));
}

void dae::Scene::Add(GameObject* object)
{
	m_pGameObjects.push_back(object);
}

void dae::Scene::Remove(GameObject* toBeDeleteGO)
{
	m_pGameObjects.erase(std::remove(m_pGameObjects.begin(), m_pGameObjects.end(), toBeDeleteGO), m_pGameObjects.end());
}

void Scene::Remove(std::shared_ptr<GameObject> object)
{
	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
}
void Scene::Remove(std::shared_ptr<TextObject> object)
{
	m_textObjects.erase(std::remove(m_textObjects.begin(), m_textObjects.end(), object), m_textObjects.end());
}

void Scene::RemoveAll()
{
	for (GameObject* c : m_pGameObjects)
	{
		delete c;
		c = nullptr;
	} //-> find a way to send messages to all gameObjects, doing this for safety for now
}

void Scene::Update( float deltaTime )
{
	for (GameObject* c : m_pGameObjects)
	{
		if (!c->HasParent())
		{
			c->Update(deltaTime);
		}
	}
}

void dae::Scene::FixedUpdate(float fixedTime)
{
	for (GameObject* c : m_pGameObjects)
	{
		if (!c->HasParent())
		{
			c->FixedUpdate(fixedTime);
		}
	}
}

void Scene::Render() const
{
	for (GameObject* c : m_pGameObjects)
	{
		c->Render();
	}
}

//BACKUP
//#include "Scene.h"
//#include "GameObject.h"
//#include "TextObject.h"
//using namespace dae;
//
//unsigned int Scene::m_idCounter = 0;
//
//Scene::Scene(const std::string& name) : m_name(name) {}
//
//Scene::~Scene() = default;
//
//void Scene::Add(std::shared_ptr<GameObject> object)
//{
//	m_objects.emplace_back(std::move(object));
//}
//
//void Scene::Add(std::shared_ptr<TextObject> object)
//{
//	m_textObjects.emplace_back(std::move(object));
//}
//
//void Scene::Remove(std::shared_ptr<GameObject> object)
//{
//	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
//}
//void Scene::Remove(std::shared_ptr<TextObject> object)
//{
//	m_textObjects.erase(std::remove(m_textObjects.begin(), m_textObjects.end(), object), m_textObjects.end());
//}
//
//void Scene::RemoveAll()
//{
//	m_objects.clear();
//}
//
//void Scene::Update([[maybe_unused]] float deltaTime)
//{
//	for (auto& object : m_objects)
//	{
//		object->Update(deltaTime);
//	}
//
//	for (auto& textObject : m_textObjects)
//	{
//		textObject->Update(deltaTime);
//	}
//}
//
//void Scene::Render() const
//{
//	for (const auto& object : m_objects)
//	{
//		object->Render();
//	}
//
//	for (const auto& textObject : m_textObjects)
//	{
//		textObject->Render();
//	}
//}

