#include "../myLL.h"

bool isPalendrome(myLL *obj)
{
    while (!obj->isEmpty())
    {
        if (obj->deleteFromHead() == obj->deleteFromTail()){}
        else 
            break;
    }

    if (!obj->isEmpty())
    {
        return false;
    }
    return true;
}

int sumLL(myLL *obj)
{
    int sum = 0;
    while (!obj->isEmpty())
    {
        sum += obj->deleteFromTail();
    }
    return sum;
}

void copyLL(myLL* obj,myLL* temp){
    int count = obj->countList();
    for(int i=0;i<count;i++){
        int val = obj->deleteFromHead();
        temp->insertAtTail(val);
        obj->insertAtTail(val);
    }
}

int main()
{
    myLL obj;
    myLL temp;
    myLL temp2;
    myLL temp3;
    obj.insertAtHead(10);
    obj.insertAtHead(21);
    obj.insertAtHead(2);
    obj.insertAtHead(10);

    copyLL(&obj,&temp);
    copyLL(&obj,&temp2);
    copyLL(&obj,&temp3);

    if (temp2.countList() == 4 && isPalendrome(&temp2) && sumLL(&temp3) > 20)
    {
        cout << "3000" << endl;
    }
    else if (isPalendrome(&obj))
    {
        cout << "2000" << endl;
    }
    else if (temp.countList() == 4 && sumLL(&temp) > 20)
    {
        cout << "1000" << endl;
    }
}