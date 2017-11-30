#pragma once
class Subject;  //Parce qu'on sera en forward declaration

class IObserver
{
public:
	virtual void notifier( Subject* subject ) = 0;
};