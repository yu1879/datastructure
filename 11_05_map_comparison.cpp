#include <iostream>
#include <time.h>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    clock_t start, finish;

    map<int, int> data_map;
    start = clock();
    for(int i=0;i<10000000;i++)
        data_map[i] = i;
    finish = clock();
    cout << "Time consumption of map: " << (finish - start)/(double) CLOCKS_PER_SEC << "s" << endl;

    unordered_map<int, int> data_unordered_map;
    start = clock();
    for(int i=0;i<10000000;i++)
        data_unordered_map[i] = i;
    finish = clock();
    cout << "Time consumption of unordered_map: " << (finish - start)/(double) CLOCKS_PER_SEC << "s" << endl;

    return 0;
}

