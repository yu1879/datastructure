#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;

    v.Pop_Back();
    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;
    v.Push_Back(4);

    for(int i=0;i<v.Size();i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
