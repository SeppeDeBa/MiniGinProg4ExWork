//INSPIRED BY MIKE SHAH, The Observer Design Pattern on his youtube and cppcon 2022, now edited with feedback from the class
// Is called a base but is more used as an interface now.
#pragma once
template<typename... Args>
class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void OnNotify() = 0;
	IObserver(const IObserver& other) = delete;
	IObserver(IObserver&& other) = delete;
	IObserver& operator=(const IObserver& other) = delete;
	IObserver& operator=(IObserver&& other) = delete;
};
