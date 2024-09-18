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

    v.Insert(5, 100);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Erase(2);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Erase(2, 4);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Clear();
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
