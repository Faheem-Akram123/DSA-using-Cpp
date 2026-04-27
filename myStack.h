#include"stack.h"
 
template <typename T>
class myStack :public Stack<T> {
public:
	myStack(const int& size);
	void push(const T& value);
	T pop();
	bool isEmpty();
	bool isFull();
	T top();
	void display();
};

template <typename T>
void myStack<T>::display() {
	for (int i = 0; i < this->currentSize; i++) {
		cout << this->stack[i] << " ";
	}
}

template <typename T>
T myStack<T>::top() {
	if (!isEmpty()) {
		return this->stack[this->currentSize - 1];
	}
	else {
		cout << "Stack is Full " << endl;
	}
}

template <typename T>
myStack<T>::myStack(const int& size):Stack<T>(size){}

template <typename T>
bool myStack<T>::isEmpty() {
	if (this->currentSize == 0) {
		return true;
	}
	return false;
}

template <typename T>
bool myStack<T>::isFull() {
	if (this->currentSize == this->maxSize) {
		return true;
	}
	return false;
}

template <typename T>
void myStack<T>::push(const T& value) {
	if (!isFull()) {
		this->stack[this->currentSize++] = value;
	}
	else {
		cout << "Stack is Full " << endl;
	}
}

template <typename T>
T myStack<T>::pop() {
	if (!isEmpty()) {
		return this->stack[--this->currentSize];
	}
	else {
		cout << "Stack is Empty" << endl;
	}
	return T();
}