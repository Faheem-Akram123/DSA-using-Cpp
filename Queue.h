#include <iostream>
using namespace std;

template <class T>
class Queue
{
//all attributes must be in parent class and should be protected
protected:
    T *arr;
    int currentSize;
    int maxSize;

//all function should be pure virtual
public:
    virtual void enqueue(T) = 0;
    virtual T dequeue() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual T peek() = 0;
    Queue(int);
    ~Queue();
};

template <class T>
Queue<T>::~Queue()
{
    delete []arr;
}

template <class T>
Queue<T>::Queue(int s)
{
    maxSize = s;
    arr = new T[s];
    currentSize = 0;
}