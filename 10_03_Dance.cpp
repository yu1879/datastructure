#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<char> boys, girls;
    int rounds, number_boy, number_girl;

    cout << "Please enter rounds, number of boys and girls:" << endl;
    cin >> rounds >> number_boy >> number_girl;

    for(int i=0;i<number_boy;i++){
        boys.push('A'+i);
    }
    for(int i=0;i<number_boy;i++){
        girls.push('a'+i);
    }

    cout << "It's party time!" << endl;
    for(int i=0;i<rounds;i++){
        char boy = boys.front();
        boys.pop();
        char girl = girls.front();
        girls.pop();
        cout << "Rounds #" << i+1 << ":" << boy << "<-->" << girl << endl;
        boys.push(boy);
        girls.push(girl);
    }

    return 0;
}
