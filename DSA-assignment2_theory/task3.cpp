#include "../myLL.h"

int main()
{
    myLL list;
    list.insertAtTail(5);
    list.insertAtTail(10);
    list.insertAtTail(4);
    list.insertAtTail(2);
    list.insertAtTail(3);

    list.sortList();
    list.display();
}