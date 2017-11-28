#pragma once
template <class T>
class Queue
{
	struct Box
	{
		T value;
		Box* next;

		Box(const T& value, Box* next) : value(value), next(next)
		{
		}
	};

	Queue(const Queue&) = delete;

	//Representation
	Box* last;
	size_t sz;

public:

	//Constructeur et affectateur
	Queue();
	~Queue();
	Queue& operator=(const Queue<T>&);

	//Accesseur
	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	//Capacite
	bool empty() const;
	size_t size() const;

	//Fonction generatrice
	void push(const T& value);
	void pop();
	void swap(Queue&) noexcept;
};

template <class T>
inline Queue<T>::Queue()
{
	last = nullptr;
	sz = 0;
}

template <class T>
inline Queue<T>::~Queue()
{
	if (sz > 0)
	{
		do
		{
			pop();
		}
		while (last != nullptr);
	}
}

template <class T>
inline Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	while (sz > other.sz)
	{
		pop();
	}

	while (sz < other.sz)
	{
		push(0);
	}

	if (other.last != nullptr)
	{
		Box* other_first = other.last->next;
		Box* this_first = last->next;

		do
		{
			this_first->value = other_first->value;
			other_first = other_first->next;
			this_first = this_first->next;
		}
		while (other.last->next != other_first);
	}

	return *this;
}

template <class T>
inline T& Queue<T>::front()
{
	return last->next->value;
}

template <class T>
inline T& Queue<T>::back()
{
	return last->value;
}

template <class T>
inline const T& Queue<T>::front() const
{
	return last->next->value;
}

template <class T>
inline const T& Queue<T>::back() const
{
	return last->value;
}

template <class T>
inline bool Queue<T>::empty() const
{
	return sz == 0;
}

template <class T>
inline size_t Queue<T>::size() const
{
	return sz;
}

template <class T>
inline void Queue<T>::push(const T& value)
{
	if (last == nullptr)
	{
		last = new Box(value, nullptr);
		last->next = last;
	}
	else
	{
		Box* old_last = last;
		last = new Box(value, last->next);
		old_last->next = last;
	}
	++sz;
}

template <class T>
inline void Queue<T>::pop()
{
	if (last->next == last)
	{
		delete last;
		last = nullptr;
	}
	else
	{
		Box* temp = last->next;
		last->next = last->next->next;
		delete temp;
	}
	--sz;
}

template <class T>
inline void Queue<T>::swap(Queue& other) noexcept
{
	std::swap(last, other.last);
	std::swap(sz, other.sz);
}
