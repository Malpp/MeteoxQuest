#pragma once

template <class T>
class Deque
{
public:
	//Ici je me définis un type non signé pour les indices et grandeurs.

	//Constructeur & destructeur
	Deque();
	~Deque();

	Deque& operator=(const Deque&);

	//Accesseur
	T& at(int) const;
	T& operator[](const unsigned int index);

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	//Capacité
	bool empty() const;
	int size() const;
	void reserve(int);
	int capacity() const;

	//Modificateur
	void clear();
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void resize(int);

private:
	Deque(const Deque& other) = delete;
	T* tab;
	int size_;
	int cap_;
	int head_;
};

template <class T>
Deque<T>::Deque()
	: size_(0),
	cap_(0),
	head_(0),
	tab(nullptr)
{
	reserve(1);
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
T& Deque<T>::at(const int index) const
{
	return tab[index];
}

template<class T>
inline T & Deque<T>::operator[]( const unsigned int index )
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
	return tab[(head_ + size_ - 1) % cap_];
}

template <class T>
const T& Deque<T>::back() const
{
	return tab[(head_ + size_ - 1) % cap_];
}

template <class T>
void Deque<T>::push_front(const T& val)
{
	resize(size_ + 1);
	--head_;
	head_ = (head_ + cap_) % cap_;
	tab[head_] = val;
}

template <class T>
void Deque<T>::push_back(const T& val)
{
	resize(size_ + 1);
	tab[(head_ + size_ - 1) % cap_] = val;
}

template <class T>
void Deque<T>::pop_front()
{
	if (size_ > 0)
	{
		--size_;
		++head_;
		head_ = (head_ + cap_) % cap_;
	}
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
	return size_ == 0;
}

template <class T>
int Deque<T>::size() const
{
	return size_;
}

template <class T>
void Deque<T>::reserve(int size)
{
	if (cap_ < size)
	{
		int old_cap = cap_;
		if (cap_ == 0)
		{
			++cap_;
		}

		while (cap_ < size)
		{
			cap_ *= 2;
		}
		T* newArray = new T[cap_];
		for (int i = 0; i < size_; ++i)
		{
			newArray[i] = tab[(head_ + i) % old_cap];
		}
		head_ = 0;
		if (tab != nullptr)
			delete[] tab;
		tab = newArray;
	}
}

template <class T>
int Deque<T>::capacity() const
{
	return cap_;
}

template <class T>
void Deque<T>::clear()
{
	delete[] tab;
	cap_ = 0;
	size_ = 0;
	head_ = 0;
}

template <class T>
void Deque<T>::resize(int new_size)
{
	if (new_size > cap_)
	{
		reserve(new_size);
	}
	size_ = new_size;
}
