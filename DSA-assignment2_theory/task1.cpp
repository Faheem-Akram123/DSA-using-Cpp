#include "../myQueue.h"

int countElements(myQueue<int> *q)
{
    myQueue<int> temp(5);
    int count = 0;
    while (!q->isEmpty())
    {
        temp.enqueue(q->dequeue());
        count++;
    }
    while (!temp.isEmpty())
    {
        q->enqueue(temp.dequeue());
    }
    return count;
}

int main()
{
    myQueue<int> q1(5);
    myQueue<int> q2(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    int count = countElements(&q1);

    cout << "Before reverse : " << endl;
    q1.display();

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            q1.enqueue(q1.dequeue());
        }
        q2.enqueue(q1.dequeue());
    }

    while (!q2.isEmpty())
    {
        q1.enqueue(q2.dequeue());
    }
    cout << "After reverse : " << endl;
    q1.display();
}