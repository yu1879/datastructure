#include <iostream>

using namespace std;

struct Node;
struct Node{
    char data;
    Node* first;
    Node* second;
    bool read_first;
};

int main() {
    Node* str_head[51];
    Node* str_tail[51];

    Node* C = new Node{'C', nullptr, nullptr, true};
    Node* B = new Node{'B', C, C, true};
    Node* A = new Node{'A', B, B, true};
    str_head[0] = A;
    str_tail[0] = C;

    for(int i=1;i<51;i++){
        C = new Node{'C', nullptr, nullptr, true};
        B = new Node{'B', str_head[i-1], str_head[i-1], true};
        A = new Node{'A', str_head[i-1], str_head[i-1], true};
        str_tail[i-1]->first = B;
        str_tail[i-1]->second = C;
        str_head[i] = A;
        str_tail[i] = C;
    }

    Node* current = str_head[50];
    for(int i=50;i<5000;i++){
        cout << current->data << "->";
        current->read_first = !(current->read_first);
        if(!(current->read_first)){
            current = current->first;
        }
        else{
            current = current->second;
        }
    }
    return 0;
}
