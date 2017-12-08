#pragma once
class Subject;  //Parce qu'on sera en forward declaration

class IObserver
{
public:
	virtual void notifier(Subject* subject, float delta_time) = 0;
};