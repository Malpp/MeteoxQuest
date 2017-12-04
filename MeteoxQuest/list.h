#ifndef _LIST_H_
#define _LIST_H_

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
class list {

private:
	struct box {
		T value;
		box *next, *prev;
		box(const T& C, box*S = nullptr, box*P = nullptr) 
		{
			value = C;
			next = S;
			prev = P;
		} //a implanter
		~box() { prev = next = nullptr; } //je vous le donne en cadeau
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
	list& operator=(const list& other);  //affectateur. copie les elements de other dans la file courante. O(n) 
	void swap(list& other); //echange les element des files courante et other O(1);

	iterator insert(iterator pos, const T& value); //ajoute un element AVANT la box en position pos. retourne un iterateur sur la nouvelle box. O(1)
	iterator erase(iterator pos); //enleve l'element a la position pos. retourne un iterateur sur l'element suivant celui qui est retire. O(1)
								  //reverse_iterator insert(reverse_iterator, const T&); //Optionnel, comme les methodes precedentes mais avec un reverse iterator
								  //reverse_iterator erase(reverse_iterator);  //Optionnel, comme les methodes precedentes mais avec un reverse iterator

	void push_back(const T& elem);  //Ajoute un element a la fin de la liste. O(1)
	void pop_back();			  //Enleve un element a la fin de la liste. O(1)
	void push_front(const T& elem); //Ajoute un element au debut de la liste. O(1)
	void pop_front();			  //Enleve un element au debut de la liste. O(1)

	T& back(); //Retourne une reference sur le dernier element de la liste. O(1)
	T& front(); //Retourne une reference sur le premier element de la liste. O(1)
	T& back() const;	//Optionnel version const de la precedente
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
	void splice(iterator pos, list& other); //Transfere les elements contenu dans other vers la liste courante. les element sont ajouter before_ la box en position pos. O(1)
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
	iterator(box*c = nullptr) :pointer_(c) {} // cadeau

	T& operator*()const //Dereference l'iterateur
	{
		return pointer_->value;
	}

	T* operator->()const //Autre dereference en cadeau.
	{
		return &(pointer_->value);
	} 

	iterator& operator++() //++i
	{
		pointer_ = pointer_->next;
		return *this;
	}

	iterator operator++(int) 
	{							 //i++
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
	{							 //i--
		iterator i(*this);
		pointer_ = pointer_->prev;
		return i;
	}

	bool operator==(const iterator&droite)const 
	{ //Cadeau! comparaison d'iterateur
		return pointer_ == droite.pointer_;
	}
	bool operator!=(const iterator&droite)const 
	{ //Cadeau! comparaison d'iterateur
		return pointer_ != droite.pointer_;
	}
};
#endif //_LIST_H

template <class T>
list<T>::list()
	: before_(NULL, nullptr, nullptr), after_(NULL, nullptr, nullptr)
{
	size_ = 0;
}

template <class T>
list<T>::~list()
{
	while (before_.next != nullptr)
	{
		box* temp = before_.next;
		before_.next = temp->next;
		delete temp;
	}

	size_ = 0;
}

template <class T>
list<T>::list(const list& other)
{
	clear();

	return *this;
}

template <class T>
void list<T>::push_back(const T& elem)
{
	if (after_.prev == nullptr)
	{
		after_.prev = new box(elem, nullptr, nullptr);
		before_.next = after_.prev;
	}
	else
	{
		after_.prev->next = new box( elem, after_.prev, nullptr );
		after_.prev = after_.prev->next;
	}
}

template <class T>
void list<T>::push_front(const T& elem)
{
	if (before_.next == nullptr)
	{
		before_.next = new box(elem, nullptr, nullptr);
		after_.prev = before_.next;
	}
	else
	{
		before_.next->prev = new box(elem, before_.next, nullptr);
		before_.next = before_.next->prev;
	}
}

template <class T>
void list<T>::pop_back()
{
	box* temp = after_.prev;
	after_.prev = temp->prev;
	delete temp;
}

template <class T>
void list<T>::pop_front()
{
	box* temp = before_.next;
	before_.next = temp->next;
	delete temp;
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
		before_.next = temp->next;
		delete temp;
	}

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
	return size_ == 0;
}

template <class T>
typename list<T>::iterator list<T>::begin()
{
	iterator i(before_.next);
	return i;
}

template <class T>
typename list<T>::iterator list<T>::end()
{
	iterator i(after_);
	return i;
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos, const T& value)
{
	insert(pos.pointer_, value);
}

template <class T>
typename list<T>::iterator list<T>::erase(iterator pos)
{
	erase(pos.pointer_);
}

template <class T>
typename list<T>::box* list<T>::insert(box* box, const T& value)
{
	list<T>::box* temp = box->prev;
	list<T>::box* new_box = new list<T>::box(value, temp, box);
	//list<T>::box->prev = new_box;
	temp->next = new_box;
	return new_box;
}

template <class T>
typename list<T>::box* list<T>::erase(box* box)
{
	list<T>::box* temp = box->next;
	box->prev->next = box->next;
	box->next->prev = box->prev;

	delete box;

	return temp;
}