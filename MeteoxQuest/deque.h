#pragma once

template <class T>
class Deque
{
public:
	//Ici je me définis un type non signé pour les indices et grandeurs.
	using size_type = unsigned long;

	//Constructeur & destructeur
	Deque();
	Deque(const Deque& other);
	~Deque();


	Deque& operator=(const Deque&);

	//Accesseur
	T& at(size_type) const;
	T& operator[](const unsigned int index);

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	//Capacité
	bool empty() const;
	size_type size() const;
	void reserve(size_type);
	size_type capacity() const;

	//Modificateur
	void clear();
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void resize(size_type);

private:
	T* tab;
	size_type size_;
	size_type cap_;
	size_type size_of_;
	size_type head_;
};

template <class T>
Deque<T>::Deque()
{
	size_ = 0;
	cap_ = 0;
	size_of_ = sizeof( T);
	reserve(1);
}

template <class T>
Deque<T>::Deque(const Deque<T>& other)
{
	size_ = 0;
	cap_ = 0;
	size_of_ = sizeof( T);
	reserve(1);
	resize(other.size());
	for (size_t i = 0; i < size_; i++)
	{
		tab[i] = other.at(i);
	}
}

template <class T>
Deque<T>::~Deque()
{
	delete[] tab;
}

template <class T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other)
{
	return *this;
}

template <class T>
T& Deque<T>::at(size_type index) const
{
	return tab[index];
}

template <class T>
T& Deque<T>::operator[](const unsigned index)
{
	return tab[index];
}

template <class T>
T& Deque<T>::front()
{
	return tab[head_];
}

template <class T>
const T& Deque<T>::front() const
{
	return tab[head_];
}

template <class T>
T& Deque<T>::back()
{
	return tab[(head_ + size_) % cap_];
}

template <class T>
const T& Deque<T>::back() const
{
	return tab[(head_ + size_) % cap_];
}

template <class T>
void Deque<T>::push_front(const T&)
{
}

template <class T>
void Deque<T>::push_back( const T& val )
{
	size_++;
	resize( size_ );
	tab[size_ - 1] = val;
}

template <class T>
void Deque<T>::pop_front()
{
}

template <class T>
void Deque<T>::pop_back()
{
	if (size_ > 0)
	{
		--size_;
	}
}

template <class T>
bool Deque<T>::empty() const
{
	return size_ == 0 ? true : false;
}

template <class T>
typename Deque<T>::size_type Deque<T>::size() const
{
	return size_;
}

template <class T>
void Deque<T>::reserve(size_type size)
{
	if (cap_ < size)
	{
		if (cap_ == 0)
		{
			++cap_;
		}

		while (cap_ < size)
		{
			cap_ *= 2;
		}
		T* newArray = new T[cap_];
		memcpy(newArray, tab, size_ * size_of_);
		delete[] tab;
		tab = newArray;
	}
}

template <class T>
typename Deque<T>::size_type Deque<T>::capacity() const
{
	return cap_;
}

template <class T>
void Deque<T>::clear()
{
	delete[] tab;
	cap_ = 0;
	size_ = 0;
}

template <class T>
void Deque<T>::resize(size_type new_size)
{
	if (new_size > cap_)
	{
		reserve(new_size);
	}
	size_ = new_size;
}
