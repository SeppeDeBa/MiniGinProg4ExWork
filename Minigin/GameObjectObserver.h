#pragma once
#include "ObserverBase.h"
#include "GameObject.h"

//NOTE:
//Create this seperately from just any watcher to not have to do dynamic casts every time to use GO functions in inherited classes from this one!
class GameObjectObserver : public ObserverBase 
{
public:
	GameObjectObserver(dae::GameObject* GOToWatch)
		:m_watchedGO{GOToWatch}
	{
		m_watchedGO->AddObserver(this);
	};
	virtual ~GameObjectObserver() 
	{
		m_watchedGO->RemoveObserver(this);//RAII working of the observer
	};
	virtual void OnNotify() = 0;


protected:
	const dae::GameObject* GetGO() const { return m_watchedGO;};


private:
	dae::GameObject* m_watchedGO;//Game Objects are BaseSubjects
};