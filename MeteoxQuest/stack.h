#pragma once

template <class T>
class Stack
{
	struct Box
	{
		T value;
		Box* next;

		Box(const T& value, Box* next) : value(value), next(next)
		{
		}
	};

	Stack(const Stack&) = delete;

	//Representation
	Box* top_;
	size_t sz_;

public:

	Stack();
	~Stack();
	Stack& operator=(const Stack<T>&);

	T& top();
	const T& top() const;

	bool empty() const;
	size_t size() const;

	void push(const T& value);
	void pop();
	void swap(Stack&) noexcept;
};

template <class T>
Stack<T>::Stack()
	: top_(nullptr), sz_(0)
{
}

template <class T>
Stack<T>::~Stack()
{
	if (top_ == nullptr)
		return;
	do
	{
		Box* temp = top_;
		top_ = top_->next;
		delete temp;
	}
	while (top_ != nullptr);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	while (sz_ > other.sz_)
	{
		pop();
	}

	while (sz_ < other.sz_)
	{
		push( 0 );
	}

	if (other.top_ != nullptr)
	{
		Box* other_top = other.top_;
		Box* this_top = top_;

		do
		{
			this_top->value = other_top->value;
			other_top = other_top->next;
			this_top = this_top->next;
		} while (other.top_->next != other_top);
	}

	return *this;
}

template <class T>
T& Stack<T>::top()
{
	return top_->value;
}

template <class T>
const T& Stack<T>::top() const
{
	return top_->value;
}

template <class T>
bool Stack<T>::empty() const
{
	return sz_ == 0;
}

template <class T>
size_t Stack<T>::size() const
{
	return sz_;
}

template <class T>
void Stack<T>::push(const T& value)
{
	top_ = new Box(value, top_);
	++sz_;
}

template <class T>
void Stack<T>::pop()
{
	Box* temp = top_;
	top_ = top_->next;
	delete temp;
	--sz_;
}

template <class T>
void Stack<T>::swap(Stack& other) noexcept
{
	std::swap( sz_, other.sz_ );
	std::swap( top_, other.top_ );
}
