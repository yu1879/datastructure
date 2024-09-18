#include <iostream>
#include "Linked_List.h"

using namespace std;

int main() {
    Linked_List<int> List;

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Push_Back(4);
    List.Push_Back(5);
    List.Push_Back(6);
    List.Push_Back(7);
    List.Push_Back(8);
    Linked_List<int>::Iterator iter1 = Find(List, 3);
    Linked_List<int>::Iterator iter2 = Find(List, 7);
    // 3 4 5 6
    List.Insert(Find(List, 4), 100);
    // 3 100 4 5 6
    for(;iter1!=iter2;iter1++)
    {
        cout << *iter1 << " ";
    }

    cout << endl;
    List.Erase(Find(List, 4));
    // 3 100 5 6

    for(iter1 = Find(List, 3);iter1!=iter2;iter1++)
    {
        cout << *iter1 << " ";
    }


    return 0;
}
