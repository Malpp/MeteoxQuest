#pragma once
#include "stdafx.h"
class IObserver;

class Subject
{
public:
	void add_observer(IObserver* observer);
	void remove_observer(IObserver* observer);
	/// <summary>
	/// Virtuel seulement pour que Subject fonctionne avec typeid
	/// </summary>
	virtual void notify_all_observers();

protected:
	std::vector<IObserver*> observers_;
};
