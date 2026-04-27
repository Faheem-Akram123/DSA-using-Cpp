/* problem

In a programming system, prefix expressions (operators first, operands second) are evaluated using a stack. In the system, the values (both operators and operands) are already placed in a queue, from left to right, following prefix order. Each element is either:
•	A positive integer operand (multi-digit allowed)
•	A negative integer operator according to the following mapping (only -1, -2, -3 allowed):
o	-1 represents PLUS (+)
o	-2 represents MULTIPLY (*)
o	-3 represents DIVIDE (/) and it works as integer division (quotient only)

You are required to read the elements from the queue one-by-one and use a stack to perform the expression evaluation in main(). At the end, the stack must contain exactly one value, which is the result of the prefix expression. Further, the following functions are available to you, please do not provide their codes: enqueue, dequeue, peek, check if queue is empty, check if queue is full, create a copy of the queue, push, pop, top, check if stack is empty, check if stack is full, create a copy of the stack. Use these functions to implement the solution in the main() function.

Example 1:
Queue contents: 	-3, -2, 7, 3, 2
Result stored in stack:    10

Evaluation steps (not to be displayed, these are for explanation and clarification only)
Step 0: Queue: -3, -2, 7, 3, 2	Stack: []
Step 1: Queue: -2, 7, 3, 2  	Stack: [-3]
Step 2: Queue: 7, 3, 2  		Stack: [-3, -2]
Step 3: Queue: 3, 2  		Stack: [-3, -2, 7]
Step 4: Queue: 2  		Stack: [-3, -2, 7, 3]
Step 5: Queue: 2  		Stack: [-3, 21]  		// Evaluated: 7 * 3 = 21
Step 6: Queue: []  		Stack: [-3, 21, 2]
Step 7: Queue: []  		Stack: [10]  		// Evaluated: 21 / 2 = 10
/Hint: When top stack values are operand, operand, operator → pop them and evaluate

Example 2:
Queue contents:	 -1, 5, -2, 2, 3
Result stored in stack: 	  11


*/

#include "../myQueue.h"
#include "../myStack.h"

int main()
{
    myQueue<int> q(5);
    myStack<int> s(5);

    q.enqueue(-3);
    q.enqueue(-2);
    q.enqueue(7);
    q.enqueue(3);
    q.enqueue(2);

    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        if (!q.isEmpty())
        {
            s.push(q.dequeue());
            count++;
        }

        if (count > 2)

        {
            int a = s.pop();
            int b = s.pop();
            if (a >= 0 && b >= 0)
            {
                int c = s.pop();
                if (c == -1)
                {
                    s.push(b + a);
                }
                else if (c == -2)
                {
                    s.push(b * a);
                }
                else if (c == -3)
                {
                    s.push(b / a);
                }
                i--;
                count -= 2;
            }
            else
            {
                s.push(b);
                s.push(a);
            }
        }
    }

    s.display();
}
