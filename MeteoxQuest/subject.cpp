#include "stdafx.h"
#include "subject.h"
#include "iobserver.h"

void Subject::add_observer( IObserver* observateur )
{
	//Si l'observateur n'est pas d�j� dans la liste...
	if (!(std::find( observers_.begin(), observers_.end(), observateur ) != observers_.end()))
	{
		observers_.push_back( observateur );
	}
}

void Subject::remove_observer( IObserver* observateur )
{
	//Pour retirer un observateur de la liste.  Deux pointeurs qui pointent � la m�me adresse sont �gaux.
	for (int i = 0; i < observers_.size(); i++)
	{
		if (observers_[i] == observateur)
		{
			observers_.erase( observers_.begin() + i );
			return;
		}
	}
}

//Suite � une action on fait toujours �a.
void Subject::notify_all_observers(const float delta_time)
{
	for (int i = 0; i < observers_.size(); i++)
	{
		observers_[i]->notifier( this, delta_time);
	}
}