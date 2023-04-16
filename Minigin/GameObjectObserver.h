#pragma once
#include "ObserverBase.h"
#include "GameObject.h"

//NOTE:
//Create this seperately from just any watcher to not have to do dynamic casts every time to use GO functions in inherited classes from this one!
//havent added rule of 3/5/6, because not sure if I want this to be an abstract class or be usable by itself.
class GameObjectObserver : public ObserverBase 
{
public:
	GameObjectObserver(dae::GameObject* GOToWatch, int message = 0)
		:m_watchedGO{ GOToWatch }
		, m_message{ message }
	{
		if (m_watchedGO != nullptr) {
			m_watchedGO->AddObserver(this, message);
		};
	};
	virtual ~GameObjectObserver() 
	{
		if (m_watchedGO != nullptr) {
			m_watchedGO->RemoveObserver(this, m_message);
		};//RAII working of the observer
	};
	virtual void OnNotify() = 0;


protected:
	dae::GameObject* GetWatchedGO() const {
		if (m_watchedGO != nullptr)  return m_watchedGO;
		else return nullptr;
	};


private:
	dae::GameObject* m_watchedGO;//Game Objects are BaseSubjects
	int m_message;
	
};