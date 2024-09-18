#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v(5);

    v[0] = 1;
    v.At(1) = 3;

    cout << v.Front() << endl;
    cout << v.At(1) << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v.Back() << endl;
    return 0;
}
