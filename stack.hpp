#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class stack {
public:
	stack();
	~stack();
	stack(stack<T> const&);
	stack<T>& operator=(stack<T> const&);

	size_t count() const;
	void push(T const &);
	T pop();

	friend void stack_last(stack<int>* _stack);

	friend void stack_print(stack<int>* _stack);

private:
	T * array_;
	size_t array_size_;
	size_t count_;
};


template <typename T>
stack<T>::stack()
{
	count_ = 0;
	array_size_ = 0;
	array_ = new T[array_size_];
}


template <typename T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}


template <typename T>
stack<T>::stack(stack<T> const& other)
{
	count_ = other.count_;
	array_size_ = other.array_size_;
	ptr_ = new T[array_size_];
	for (unsigned int i = 0; i < count_; i++)
	{
		array_[i] = other.array_[i];
	}
}


template <typename T>
stack<T>& stack<T>::operator=(stack<T> const& other)
{
	if (this != &other)
	{
		delete[] array_;
		count_ = other.count_;
		array_size_ = other.array_size_;
		array_ = new T[array_size_];
		for (unsigned int i = 0; i < count_; i++)
		{
			array_[i] = other.array_[i];
		}
	}

	return *this;
}


template <typename T>
size_t stack<T>::count() const
{
	return count_;
}


template <typename T>
void stack<T>::push(T const& obj)
{
	if (array_size_ == 0)
	{
		delete[] array_;
		array_size_ = 1;
		array_ = new int[array_size_]();
	}
	else if (count_ + 1 >= array_size_)
	{
		array_size_ *= 2;
		T* narray = new int[array_size_]();
		for (unsigned int i = 0; i < count_; i++)
		{
			narray[i] = array_[i];
		}
		delete[] array_;
		array_ = narray;
	}
	array_[count_++] = obj;
}


template <typename T>
T stack<T>::pop()
{
	if (count_ == 0)
		throw "Stack is empty!";

	count_--;
	T obj = array_[count_];

	return obj;
}


#endif
