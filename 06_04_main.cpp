#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);

    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    Vector<int>::Iterator iter = v.Begin();

    v.Insert(iter + 5, 100);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Erase(iter + 2);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Erase(iter+2, iter+4);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Clear();
    cout << v.Size() << endl;
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
