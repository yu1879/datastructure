#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person<int> p1("Rallod", 170,50);
    Person<float> p2("Mick",168,60);
    // p.set_name("LKM");
    // p.set_height(168);
    // p.set_weight(60);

    // p.print();
    // print(p1);
    // print(p2);

    // cin >> p1;
    cin >> p1;
    // cout << p1;
    cout << p1;

    return 0;
}
