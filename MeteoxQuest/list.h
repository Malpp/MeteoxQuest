#ifndef _LIST_H_
#define _LIST_H_
#include <algorithm>
#include <list>
#include <complex.h>

/**********************************************************
Description de la representation

Chaine double de boites
Une box supplementaire a la fin,
nommee after_ en memoire automatique (non dynamique)
Une box supplementaire au debut nommee before_
en memoire automatique (non dynamique) dont le suivant
pointe sur la premiere box
size_ contient le nombre d'elements dans la liste


iterator: pointeur sur la box concernee,
la fin est un pointeur sur la box de queue (after_)

reverse_iterator: pointeur sur la box qui concernee
(rbegin: celle pointe par le precedent de after_, rend: before_)

RESTRICTION par rapport a la SL
pas de const_iterator, donc pas d'iteration possible
sur une list const.

**********************************************************/

template <class T>
class list
{
private:
	struct box
	{
		T value;
		box* next, * prev;

		box(const T& C, box* S = nullptr, box* P = nullptr)
		{
			value = C;
			next = S;
			prev = P;
		} //a implanter
		~box()
		{
			prev = next = nullptr;
		} //je vous le donne en cadeau
	};

	box before_;
	box after_;
	size_t size_;

	//fonctions generatrices privees
	box* insert(box*, const T&); //inserer avant cette box 
	box* erase(box*); //enlever cette box

public:
	class iterator;
	//class const_iterator; //Optionnel
	//class reverse_iterator; //Optionnel
	//class const_reverse_iterator; //Optionnel

	list(); //constructeur
	~list(); //destructeur
	list(const list&); //copie constructeur
	list(std::initializer_list<T>);
	list& operator=(const list& other);
	//affectateur. copie les elements de other dans la file courante. O(n) 
	void swap(list& other) noexcept;
	//echange les element des files courante et other O(1);

	iterator insert(iterator pos, const T& value);
	//ajoute un element AVANT la box en position pos. retourne un iterateur sur la nouvelle box. O(1)
	iterator erase(iterator pos);
	//enleve l'element a la position pos. retourne un iterateur sur l'element suivant celui qui est retire. O(1)
	//reverse_iterator insert(reverse_iterator, const T&); //Optionnel, comme les methodes precedentes mais avec un reverse iterator
	//reverse_iterator erase(reverse_iterator);  //Optionnel, comme les methodes precedentes mais avec un reverse iterator

	void push_back(const T& elem);
	//Ajoute un element a la fin de la liste. O(1)
	void pop_back(); //Enleve un element a la fin de la liste. O(1)
	void push_front(const T& elem);
	//Ajoute un element au debut de la liste. O(1)
	void pop_front(); //Enleve un element au debut de la liste. O(1)

	T& back();
	//Retourne une reference sur le dernier element de la liste. O(1)
	T& front();
	//Retourne une reference sur le premier element de la liste. O(1)
	T& back() const; //Optionnel version const de la precedente
	T& front() const; //Optionnel version const de la precedente

	void clear();
	size_t size() const;
	bool empty() const;

	iterator begin(); //Retourne un iterateur sur la box suivant before_.
	iterator end(); //Retourne un iterateur sur la box after_.
	//reverse_iterator rbegin(); //Optionnel version inverse des methodes precedentes
	//reverse_iterator rend(); //Optionnel version inverse des methodes precedentes

	//algorithmes
	void reverse(); //Inverse l'ordre des elements de la liste. O(n)
	void splice(iterator pos, list& other);
	//Transfere les elements contenu dans other vers la liste courante. les element sont ajouter avant la box en position pos. O(1)
	//void resize(size_t newSize, const T& value= T()); //Optionnel permet d'ajuster le nombre d'element de la liste. initialise les nouveaux element a value. Potentiellement O(n)
};

///////////////////////////////////////////////////////////
//la classe iterator
///////////////////////////////////////////////////////////

template <typename T>
class list<T>::iterator
{
	friend class list<T>;
private:
	box* pointer_;
public:
	iterator(box* c = nullptr)
		: pointer_(c)
	{
	} // cadeau

	T& operator*() const //Dereference l'iterateur
	{
		return pointer_->value;
	}

	T* operator->() const //Autre dereference en cadeau.
	{
		return &(pointer_->value);
	}

	iterator& operator++() //++i
	{
		pointer_ = pointer_->next;
		return *this;
	}

	iterator operator++(int)
	{
		//i++
		iterator i(*this);
		pointer_ = pointer_->next;
		return i;
	}

	iterator& operator--() //--i
	{
		pointer_ = pointer_->prev;
		return *this;
	}

	iterator operator--(int)
	{
		//i--
		iterator i(*this);
		pointer_ = pointer_->prev;
		return i;
	}

	bool operator==(const iterator& droite) const
	{
		//Cadeau! comparaison d'iterateur
		return pointer_ == droite.pointer_;
	}

	bool operator!=(const iterator& droite) const
	{
		//Cadeau! comparaison d'iterateur
		return pointer_ != droite.pointer_;
	}
};
#endif //_LIST_H

template <class T>
list<T>::list()
	: before_(0, nullptr, nullptr)
	, after_(0, nullptr, nullptr)
{
	size_ = 0;
}

template <class T>
list<T>::~list()
{
	box* temp = before_.next;
	while(before_.next != nullptr)
	{
		temp = before_.next;
		before_.next = temp->next;
		delete temp;
	}
	before_.next, after_.prev = nullptr;
	size_ = 0;
}

template <class T>
list<T>::list(const list& other)
	: before_(NULL, nullptr, nullptr)
	, after_(NULL, nullptr, nullptr)
{
	*this = other;
}

template <class T>
list<T>& list<T>::operator=(const list& other)
{
	if (!empty())
	{
		clear();
	}

	box* current = nullptr;
	box* other_current = other.before_.next;
	while (other_current != nullptr)
	{
		if (current == nullptr)
		{
			before_.next = current = new box(other_current->value, nullptr, nullptr);
		}
		else
		{
			current->next = new box(other_current->value, nullptr, current);
			current = current->next;
		}
		other_current = other_current->next;
	}
	after_.prev = current;
	size_ = other.size_;
	return *this;
}

template <class T>
void list<T>::swap(list<T>& other) noexcept
{
	std::swap(before_, other.before_);
	std::swap(after_, other.after_);
	std::swap(size_, other.size_);
}

template <class T>
void list<T>::push_back(const T& value)
{
	if(after_.prev == nullptr)
	{
		after_.prev = new box(value, nullptr, nullptr);
		before_.next = after_.prev;
	}
	else
	{
		after_.prev->next = new box(value, nullptr, after_.prev);
		after_.prev = after_.prev->next;
	}
	++size_;
}

template <class T>
void list<T>::push_front(const T& elem)
{
	if(before_.next == nullptr)
	{
		before_.next = new box(elem, nullptr, nullptr);
		after_.prev = before_.next;
	}
	else
	{
		before_.next->prev = new box(elem, before_.next, nullptr);
		before_.next = before_.next->prev;
	}
	++size_;
}

template <class T>
void list<T>::pop_back()
{
	box* temp = after_.prev;
	if (after_.prev != before_.next)
	{
		after_.prev = after_.prev->prev;
		after_.prev->next = nullptr;
	}
	else
	{
		before_.next, after_.prev = nullptr;
	}
		
	delete temp;
	--size_;
}

template <class T>
void list<T>::pop_front()
{
	box* temp = before_.next;	
	if (before_.next != after_.prev)
	{
		before_.next = before_.next->next;
		before_.next->prev = nullptr;
	}
	else
	{
		before_.next, after_.prev = nullptr;
	}
	
	delete temp;
	--size_;
}

template <class T>
T& list<T>::front()
{
	return before_.next->value;
}

template <class T>
T& list<T>::front() const
{
	return before_.next->value;
}

template <class T>
T& list<T>::back()
{
	return after_.prev->value;
}

template <class T>
T& list<T>::back() const
{
	return after_.prev->value;
}

template <class T>
void list<T>::clear()
{	
	while (before_.next != nullptr)
	{
		box* temp = before_.next;
		before_.next = before_.next->next;		
		delete temp;
		if (before_.next != nullptr)
			before_.next->prev = nullptr;
	}
	before_.next, after_.prev = nullptr;
	size_ = 0;
}

template <class T>
size_t list<T>::size() const
{
	return size_;
}

template <class T>
bool list<T>::empty() const
{
	return before_.next == nullptr && after_.prev == nullptr;
}

template <class T>
typename list<T>::iterator list<T>::begin()
{
	return before_.next;
}

template <class T>
typename list<T>::iterator list<T>::end()
{
	return &after_;
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos, const T& value)
{
	iterator i(insert(pos.pointer_, value));
	++size_;
	return i;
}

template <class T>
typename list<T>::iterator list<T>::erase(iterator pos)
{
	iterator i(erase(pos.pointer_));
	--size_;
	return i;
}

template <class T>
typename list<T>::box* list<T>::insert(box* box, const T& value)
{
	if (box == before_.next)
	{
		before_.next->prev = new typename list<T>::box(value, before_.next, nullptr);
		before_.next = before_.next->prev;
		return before_.next;
	}

	if (box == &after_)
	{
		after_.prev->next = new typename list<T>::box(value, nullptr, after_.prev);
		after_.prev = after_.prev->next;
		return after_.prev;
	}

	if (box != before_.next && box != &after_)
	{
		typename list<T>::box* new_box = new typename list<T>::box(value,box->next,box->prev);
		box->prev->next = new_box;
		box->prev = new_box;
		return new_box;
	}
}

template <class T>
typename list<T>::box* list<T>::erase(box* box)
{
	if (box == before_.next)
	{
		typename list<T>::box* temp = before_.next;
		before_.next = before_.next->next;
		before_.next->prev = nullptr;
		delete temp;
		return before_.next;
	}

	if (box == after_.prev)
	{
		typename list<T>::box* temp = after_.prev;
		after_.prev = after_.prev->prev;
		after_.prev->next = nullptr;
		delete temp;
		return &after_;
	}

	if (box != before_.next && box != after_.prev)
	{
		typename list<T>::box* temp = box;
		typename list<T>::box* box_prev = box->prev;
		typename list<T>::box* box_next = box->next;
		box_next->prev = box_prev;
		box_prev->next = box_next;
		delete temp;
		return box_next;
	}
}

template <class T>
void list<T>::reverse()
{
	typename list<T>::iterator i(before_.next);
	typename list<T>::iterator j(after_.prev);
	while(!(i == j) && !(++j == i))
	{
		box* temp = i.pointer_;
		i.pointer_ = j.pointer_;
		j.pointer_ = temp;
		++i;
		--j;
	}
}

template <class T>

void list<T>::splice(typename list<T>::iterator pos, list<T>& other)
{
	std::list<T>::splice(pos, other);
}
