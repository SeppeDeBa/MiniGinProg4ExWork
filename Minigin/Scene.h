#pragma once
#include "SceneManager.h"

namespace dae
{
	class GameObject;
	class TextObject;
	class Scene final
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(std::shared_ptr<GameObject> object);
		void Add(std::shared_ptr<TextObject> object);
		void Add(GameObject* object);
		void Remove(GameObject* toBeDeleteGO);
		void Remove(std::shared_ptr<GameObject> object);
		void Remove(std::shared_ptr<TextObject> object);
		//void Remove();
		void RemoveAll();

		void Update(float deltaTime);
		void Render() const;

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string m_name;
		std::vector<GameObject*> m_pGameObjects;
		std::vector < std::shared_ptr<GameObject>> m_objects{};
		std::vector < std::shared_ptr<TextObject>> m_textObjects{};

		static unsigned int m_idCounter; 
	};

}
//BACKUP
//#pragma once
//#include "SceneManager.h"
//
//namespace dae
//{
//	class GameObject;
//	class TextObject;
//	class Scene final
//	{
//		friend Scene& SceneManager::CreateScene(const std::string& name);
//	public:
//		void Add(std::shared_ptr<GameObject> object);
//		void Add(std::shared_ptr<TextObject> object);
//		void Remove(std::shared_ptr<GameObject> object);
//		void Remove(std::shared_ptr<TextObject> object);
//		void RemoveAll();
//
//		void Update(float deltaTime);
//		void Render() const;
//
//		~Scene();
//		Scene(const Scene& other) = delete;
//		Scene(Scene&& other) = delete;
//		Scene& operator=(const Scene& other) = delete;
//		Scene& operator=(Scene&& other) = delete;
//
//	private:
//		explicit Scene(const std::string& name);
//
//		std::string m_name;
//		//std::vector<GameObject*> m_pGameObjects;
//		std::vector < std::shared_ptr<GameObject>> m_objects{};
//		std::vector < std::shared_ptr<TextObject>> m_textObjects{};
//
//		static unsigned int m_idCounter;
//	};
//
//}