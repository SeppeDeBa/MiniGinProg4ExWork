//INSPIRED BY MIKE SHAH, The Observer Design Pattern on his youtube and cppcon 2022
#pragma once

class ObserverBase
{
public:
	ObserverBase() {};
	virtual ~ObserverBase() {};
	virtual void OnNotify() = 0;
	ObserverBase(const ObserverBase& other) = delete;
	ObserverBase(ObserverBase&& other) = delete;
	ObserverBase& operator=(const ObserverBase& other) = delete;
	ObserverBase& operator=(ObserverBase&& other) = delete;
};

