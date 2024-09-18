#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v(5);

    cout << v.Front() << endl;
    cout << v.Back() << endl;
    return 0;
}
