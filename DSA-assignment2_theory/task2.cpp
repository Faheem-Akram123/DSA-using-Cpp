#include "../myQueue.h"

int main()
{
    myQueue<int> q1(7);
    myQueue<int> q2(7);

    q1.enqueue(3);
    q1.enqueue(1);
    q1.enqueue(4);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(2);
    q1.enqueue(1);

    int first = q1.peek();
    int value = first;

    while (!q1.isEmpty())
    {
        value = q1.dequeue();
        while (!q1.isEmpty())
        {
            if (value != q1.peek())
            {
                q2.enqueue(q1.dequeue());
            }
            else
            {
                q1.dequeue();
            }
        }
        q2.enqueue(value);

        if (first == q2.peek())
        {
            while (!q2.isEmpty())
            {
                q1.enqueue(q2.dequeue());
            }
            break;
        }
        else
        {
            while (!q2.isEmpty())
            {
                q1.enqueue(q2.dequeue());
            }
        }
    }

    q1.display();
}
