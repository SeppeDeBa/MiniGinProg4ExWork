//INSPIRED BY MIKE SHAH, The Observer Design Pattern on his youtube and cppcon 2022
#pragma once
#include "ObserverBase.h"
#include <forward_list>
class SubjectBase
{
public:
	SubjectBase() {};
	virtual ~SubjectBase() {};

	virtual void AddObserver(ObserverBase* observerToAdd)
	{
		m_observers.push_front(observerToAdd);
	}
	
	virtual void RemoveObserver(ObserverBase* observerToRemove)
	{
		m_observers.remove(observerToRemove);
	}

	void NotifyAll() 
	{
		for (auto& observer : m_observers)
		{
			observer->OnNotify();
		}
	}
	
	//virtual void AddObserver

private:

	std::forward_list<ObserverBase*> m_observers{}; //testing out forward list for experience here.

	
};

