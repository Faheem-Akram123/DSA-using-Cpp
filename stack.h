#include<iostream>
using namespace std;

template <typename T>
class Stack {
protected:
	T* stack;
	int maxSize;
	int currentSize;
public:
	Stack(const int& size);
	virtual void push(const T& value) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T top() = 0;
	~Stack();
};

template <typename T>
Stack<T>::Stack(const int& size) {
	maxSize = size;
	currentSize = 0;

	stack = new T[maxSize];
}

template <typename T>
Stack<T>::~Stack() {
	delete[]stack;
}