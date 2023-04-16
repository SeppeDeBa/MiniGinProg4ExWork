//INSPIRED BY MIKE SHAH, The Observer Design Pattern on his youtube and cppcon 2022
#pragma once
#include "ObserverBase.h"
#include <forward_list>
#include <map>
class SubjectBase //could maybe be set to final, waiting on feedback if this should be specifically inherited to a GOSubject
{
public:
	//MESSAGES THAT CAN BE SENT
	enum messageTypes 
	{ 
		HEALTHSYSTEM,
		SCORESYSTEM
	}; 

	SubjectBase() {};
	virtual ~SubjectBase() {};

	//message is enum
	virtual void AddObserver(ObserverBase* observerToAdd, int message)
	{
		//search for enum
		auto iterator = m_observers.find(message);
		if (iterator == m_observers.end())
		{
			m_observers[message] = ObserversList(); //when it hasn't found a lists that exists with such message, it creates a new one
		}
		m_observers[message].push_front(observerToAdd);
	}
	
	virtual void RemoveObserver(ObserverBase* observerToRemove, int message)
	{
		auto iterator = m_observers.find(message);
		if (iterator != m_observers.end()) //when the bucket is found in the list
		{
			//iterate through list in the buckets
			ObserversList& list = m_observers[message];//this just to not have to type the whole screen and pollute the function
			
			for (ObserversList::iterator listIterator = list.begin(); listIterator != list.end();)
			{
				if ((*listIterator) == observerToRemove)
				{
					list.remove(observerToRemove);
				}
				else ++listIterator;
				//For loop inspired by Mike Shah, The observer design pattern in c++ part 4, manual iteration
			}

		}
	}

	void NotifyAll() 
	{

		for (ObserversMap::iterator it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			for (auto& observer : m_observers[it->first])
			{
				observer->OnNotify();
			}
		}
	}
	
	void Notify(int message)
	{
		for (auto& observer : m_observers[message])
		{
			observer->OnNotify();
		}
	}


	//virtual void AddObserver

private:
	//TODO: check difference sith typedef vs using for modern cpp implementation
	typedef std::forward_list<ObserverBase*> ObserversList; //testing out forward list for experience here.
	typedef std::map<int, ObserversList> ObserversMap;
	// Key/Value pair
	// Key = int / enum
	// Value = std::forward_list of Observers (can be any since we're using the baseClass)
	ObserversMap m_observers{};
};

