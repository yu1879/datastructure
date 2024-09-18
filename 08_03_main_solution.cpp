#include <iostream>
#include "Circular_Linked_List.h"

using namespace std;

int main() {
    Linked_List<int> List;

    /*
    List.Push_Back(2);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Push_Back(4);
    List.Push_Back(2);
    List.Push_Back(2);
    List.Push_Back(7);
    List.Push_Back(2);
    for(auto iter=List.Begin();iter != List.End();iter++){
        cout << *iter << " ";
    }
    cout << endl;
    for(auto iter=Begin(List);iter != End(List);iter++){
        cout << *iter << " ";
    }
    cout << endl;

    auto iter=Begin(List);
    Advance(iter, 3);
    cout << *iter << endl;
    // 4

    Advance(iter, -2);
    cout << *iter << endl;
    // 2

    auto iter_1 = Find(List, 5);
    auto iter_2 = Find(List, 8);
    cout << Distance(iter_1, iter_2);
    // 3

    for(auto iter=List.Begin();iter != List.End();iter++){
        cout << *iter << " ";
    }
    cout << endl;
    List.Remove(2);
    for(auto iter=List.Begin();iter != List.End();iter++){
        cout << *iter << " ";
    }
    */

    // Circular test
    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Push_Back(4);
    List.Push_Back(5);
    List.Push_Back(6);
    List.Push_Back(7);
    List.Push_Back(8);
    bool first = true;
    for(auto iter=List.Begin();iter != List.Begin() || first;iter++){
        cout << *iter << " ";
        if(first)
            first = false;
    }
    cout << endl;

    List.Rotate(3);
    first = true;
    for(auto iter=List.Begin();iter != List.Begin() || first;iter++){
        cout << *iter << " ";
        if(first)
            first = false;
    }

    return 0;
}
