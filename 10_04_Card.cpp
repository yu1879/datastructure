#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N;
    cout << "Please enter N:";
    cin >> N;
    deque<int> data;

    for(int i=1;i<=N;i++)
        data.push_back(i);

    while(data.size()>1){
        data.pop_front();
        int tmp = data.front();
        data.pop_front();
        data.push_back(tmp);
    }
    cout << "Last: " << data.front() << endl;

    return 0;
}
