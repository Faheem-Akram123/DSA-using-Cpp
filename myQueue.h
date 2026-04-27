#include "Queue.h"

template <class T>
class myQueue:public Queue<T>
{
public:
    void enqueue(T);
    myQueue(int size);
    void display();
    T dequeue();
    T peek();
    bool isEmpty();
    bool isFull();
};

template <class T>
T myQueue<T>::peek()             //O(1)
{
    if (isEmpty())
    {
        cout << "Queue is empty, I am returning ZERO" << endl;
        return 0;
    }

    else
    {
        return this->arr[0];
    }
}

template <class T>
bool myQueue<T>::isFull()           //O(1)
{
    return this->currentSize == this->maxSize;
}

template <class T>
bool myQueue<T>::isEmpty()          //O(1)
{
    return this->currentSize == 0;
}

template <class T>
T myQueue<T>::dequeue()             //O(N)
{
    if (isEmpty())
    {
        cout << "Queue is empty, I am returning ZERO" << endl;
        return 0;
    }

    else
    {
        T returningValue = this->arr[0];
        this->currentSize --;

        for (int i=0; i<this->currentSize; i++)
            this->arr[i] = this->arr[i+1];

        return returningValue;

    }
}

template <class T>
void myQueue<T>::enqueue(T value)          //O(1)
{
    if (!isFull())
    {
        this->arr[Queue<T>::currentSize] = value;
        this->currentSize++;
    }

    else
        cout << "Queue is FULL" << endl;
}

template <class T>
myQueue<T>::myQueue(int size):Queue<T>(size)        //O(1)
{

}

template <class T>
void myQueue<T>::display()                          //O(N)
{
    cout << "Max Size: " << Queue<T>::maxSize << endl;
    cout << "Current Size: " << Queue<T>::currentSize << endl;

    for (int i = 0; i <this->currentSize; i++)
        cout << i << ". " << this->arr[i] << endl;
}