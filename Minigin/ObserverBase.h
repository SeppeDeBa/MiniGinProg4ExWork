//INSPIRED BY MIKE SHAH, The Observer Design Pattern on his youtube and cppcon 2022
#pragma once
class ObserverBase
{
public:
	virtual ~ObserverBase() {};
	virtual void OnNotify() = 0;
};

