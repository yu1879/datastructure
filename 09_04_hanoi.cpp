#include <iostream>
#include <stack>

using namespace std;

stack<int> A;
stack<int> B;
stack<int> C;

void print_stack(stack<int>& s){
    if(s.empty())
        return ;
    int data = s.top();
    s.pop();
    print_stack(s);
    cout << data << " ";
    s.push(data);
}

void print_all(){
    cout << "\nA:";
    print_stack(A);
    cout << "\nB:";
    print_stack(B);
    cout << "\nC:";
    print_stack(C);
    cout << "\n-------------";
}

void Hanoi(int N, stack<int>& from, stack<int>& to, stack<int>& others){
    if(N==1){
        //Move 1 plate from->to
        to.push(from.top());
        from.pop();
        print_all();
        return;
    }
    else{
        // Move N-1 plates from->others
        Hanoi(N-1, from, others, to);
        // Move 1 plate from->to
        to.push(from.top());
        from.pop();
        print_all();
        // Move N-1 plates others->to
        Hanoi(N-1, others, to, from);
    }
}

int main () {
    int N;
    cout << "Please enter N:" << endl;
    cin >> N;

    for(int i=N;i>0;i--)
        A.push(i);

    Hanoi(N, A, C, B);

    return 0;
}

