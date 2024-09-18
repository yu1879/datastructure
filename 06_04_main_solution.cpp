#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(2);
    v.Push_Back(2);
    v.Push_Back(6);
    v.Push_Back(2);

    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    auto iter = Remove(v, 2);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    /*
    Vector<int>::Iterator iter;
    iter = Find(v, 6);

    if(iter != v.End()){
        cout << *iter << endl;
    }
    else
        cout << "Not found!" << endl;
    */

    return 0;
}
