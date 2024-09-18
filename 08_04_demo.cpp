#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> data;
    int value;

    do{
        cout << "Please enter a value:" << endl;
        cin >> value;
        if(value)
            data.push_back(value);
    }
    while(value);

    for(auto iter = data.begin();iter != data.end();iter++){
        cout << *iter << " ";
    }

    return 0;
}
