#ifndef _LIST_H_
#define _LIST_H_

/**********************************************************
Description de la representation

Chaine double de boites
Une boite supplementaire a la fin,
nommee apres en memoire automatique (non dynamique)
Une boite supplementaire au debut nommee avant
en memoire automatique (non dynamique) dont le suivant
pointe sur la premiere boite
size contient le nombre d'elements dans la liste


iterator: pointeur sur la boite concernee,
la fin est un pointeur sur la boite de queue (apres)

reverse_iterator: pointeur sur la boite qui concernee
(rbegin: celle pointe par le precedent de apres, rend: avant)

RESTRICTION par rapport a la SL
pas de const_iterator, donc pas d'iteration possible
sur une list const.

**********************************************************/

template <class TYPE>
class list {

private:
	struct boite {
		TYPE valeur;
		boite *suiv, *prec;
		boite(const TYPE& C, boite*S = nullptr, boite*P = nullptr) 
		{
			valeur = C;
			suiv = S;
			prec = P;
		} //a implanter
		~boite() { prec = suiv = nullptr; } //je vous le donne en cadeau
	};
	boite avant;
	boite apres;
	size_t size;

	//fonctions generatrices privees
	boite* insert(boite*, const TYPE&); //inserer avant cette boite 
	boite* erase(boite*); //enlever cette boite

public:
	class iterator;
	//class const_iterator; //Optionnel
	//class reverse_iterator; //Optionnel
	//class const_reverse_iterator; //Optionnel

	list(); //constructeur
	~list(); //destructeur
	list(const list&); //copie constructeur
	list(std::initializer_list<TYPE>);
	list& operator=(const list& other);  //affectateur. copie les elements de other dans la file courante. O(n) 
	void swap(list& other); //echange les element des files courante et other O(1);

	iterator insert(iterator pos, const TYPE& value); //ajoute un element AVANT la boite en position pos. retourne un iterateur sur la nouvelle boite. O(1)
	iterator erase(iterator pos); //enleve l'element a la position pos. retourne un iterateur sur l'element suivant celui qui est retire. O(1)
								  //reverse_iterator insert(reverse_iterator, const TYPE&); //Optionnel, comme les methodes precedentes mais avec un reverse iterator
								  //reverse_iterator erase(reverse_iterator);  //Optionnel, comme les methodes precedentes mais avec un reverse iterator

	void push_back(const TYPE& elem);  //Ajoute un element a la fin de la liste. O(1)
	void pop_back();			  //Enleve un element a la fin de la liste. O(1)
	void push_front(const TYPE& elem); //Ajoute un element au debut de la liste. O(1)
	void pop_front();			  //Enleve un element au debut de la liste. O(1)

	TYPE& back(); //Retourne une reference sur le dernier element de la liste. O(1)
	TYPE& front(); //Retourne une reference sur le premier element de la liste. O(1)
	TYPE& back() const;	//Optionnel version const de la precedente
	TYPE& front() const; //Optionnel version const de la precedente

	void clear();
	size_t size() const;
	bool empty() const;

	iterator begin(); //Retourne un iterateur sur la boite suivant avant.
	iterator end(); //Retourne un iterateur sur la boite apres.
					//reverse_iterator rbegin(); //Optionnel version inverse des methodes precedentes
					//reverse_iterator rend(); //Optionnel version inverse des methodes precedentes

					//algorithmes
	void reverse(); //Inverse l'ordre des elements de la liste. O(n)
	void splice(iterator pos, list& other); //Transfere les elements contenu dans other vers la liste courante. les element sont ajouter avant la boite en position pos. O(1)
											//void resize(size_t newSize, const TYPE& valeur= TYPE()); //Optionnel permet d'ajuster le nombre d'element de la liste. initialise les nouveaux element a valeur. Potentiellement O(n)
};

///////////////////////////////////////////////////////////
//la classe iterator
///////////////////////////////////////////////////////////

template <typename TYPE>
class list<TYPE>::iterator {
	friend class list<TYPE>;
private:
	boite* POINTEUR;
public:
	iterator(boite*c = nullptr) :POINTEUR(c) {} // cadeau
	TYPE& operator*()const //Dereference l'iterateur
	{
		return POINTEUR->CONTENU;
	}

	TYPE* operator->()const { return &(POINTEUR->CONTENU); } //Autre dereference en cadeau.

	iterator& operator++() //++i
	{
		POINTEUR = POINTEUR->CONTENU->suiv;
		return *this;
	}

	iterator operator++(int) 
	{							 //i++
		iterator i(*this);
		POINTEUR = POINTEUR->CONTENU->suiv;
		return i;
	}

	iterator& operator--() //--i
	{
		POINTEUR = POINTEUR->CONTENU->prec;
		return *this;
	}
	iterator operator--(int) 
	{							 //i--
		iterator i(*this);
		POINTEUR = POINTEUR->CONTENU->prec;
		return i;
	}

	bool operator==(const iterator&droite)const { //Cadeau! comparaison d'iterateur
		return POINTEUR == droite.POINTEUR;
	}
	bool operator!=(const iterator&droite)const { //Cadeau! comparaison d'iterateur
		return POINTEUR != droite.POINTEUR;
	}
};
#endif //_LIST_H

template <class TYPE>
list<TYPE>::list()
{
	avant, apres = new boite(0, nullptr, nullptr);
	size = 0;
}

template <class TYPE>
list<TYPE>::~list()
{
	while (avant->suiv != nullptr)
	{
		boite* temp = avant->suiv;
		avant->suiv = temp->suiv;
		delete temp;
	}

	size = 0;
}

template <class TYPE>
list<TYPE>::list(const list& other)
{
	clear();

	return *this;
}

template <class TYPE>
void list<TYPE>::push_back(const TYPE& elem)
{
	if (apres->prec == nullptr)
	{
		apres->prec = new boite(elem, nullptr, nullptr);
		avant->suiv = apres->prec;
	}
	else
	{
		apres->prec->suiv = new boite(elem, apres->prec, nullptr);
		apres->prec = apres->prec->suiv;
	}	
}

template <class TYPE>
void list<TYPE>::push_front(const TYPE& elem)
{
	if (avant->suiv == nullptr)
	{
		avant->suiv = new boite(elem, nullptr, nullptr);
		apres->prec = avant->suiv;
	}
	else
	{
		avant->suiv->prec = new boite(elem, avant->suiv, nullptr);
		avant->suiv = avant->suiv->prec;
	}
}

template <class TYPE>
void list<TYPE>::pop_back()
{
	boite* temp = apres->prec;
	apres->prec = temp->prec;
	delete temp;
}

template <class TYPE>
void list<TYPE>::pop_front()
{
	boite* temp = avant->suiv;
	avant->suiv = temp->suiv;
	delete temp;
}

template <class TYPE>
TYPE& list<TYPE>::front()
{
	return avant->suiv;
}

template <class TYPE>
TYPE& list<TYPE>::front() const
{
	return avant->suiv;
}

template <class TYPE>
TYPE& list<TYPE>::back()
{
	return apres->prec;
}

template <class TYPE>
TYPE& list<TYPE>::back() const
{
	return apres->prec;
}

template <class TYPE>
void list<TYPE>::clear()
{
	while (avant->suiv != nullptr)
	{
		boite* temp = avant->suiv;
		avant->suiv = temp->suiv;
		delete temp;
	}

	size = 0;
}

template <class TYPE>
size_t list<TYPE>::size() const
{
	return size;
}

template <class TYPE>
bool list<TYPE>::empty() const
{
	return size == 0;
}

template <class TYPE>
iterator list<TYPE>::begin()
{
	iterator i(avant->suiv);
	return i;
}

template <class TYPE>
iterator list<TYPE>::end()
{
	iterator i(apres->prec);
	return i;
}

template <class TYPE>
iterator list<TYPE>::erase(list<TYPE>::iterator pos)
{
	
}

template <class TYPE>
iterator list<TYPE>::insert(list<TYPE>::iterator pos, const TYPE& value)
{
	
}