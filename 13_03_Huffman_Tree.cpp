#include <iostream>
#include <queue>

using namespace std;

struct Node;
struct Node{
    char character;
    int counts;
    Node* left;
    Node* right;
};
typedef struct Node Node;

class Compare{
    public:
        bool operator()(Node* n1,Node* n2){
            return n1->counts > n2->counts;
        }
};

class Huffman_Tree{
    private:
        priority_queue<Node*, vector<Node*>, Compare> all_nodes;
        Node* Pop_Node();
    public:
        Node* root_node;
        Huffman_Tree();
        void Clear_Queue();
        void Insert(char,int);
        void Build_Huffman_Tree();
        void Print_Code_Table();
        void Traversal(Node*,queue<char>);
};

Huffman_Tree::Huffman_Tree(){
    root_node = nullptr;
}

Node* Huffman_Tree::Pop_Node(){
    if(all_nodes.empty())
        return nullptr;
    else{
        Node* tmp = all_nodes.top();
        all_nodes.pop();
        return tmp;
    }
}

void Huffman_Tree::Insert(char c, int frequency){
    all_nodes.push(new Node{c, frequency, nullptr, nullptr});
}

void Huffman_Tree::Clear_Queue(){
    cout << "Start to clear priority queue in this Huffman Tree..." << endl;
    while(!all_nodes.empty()){
        Node* tmp = all_nodes.top();
        cout << "Char: " << tmp->character << ", Counts: " << tmp->counts << endl;
        all_nodes.pop();
    }
}

void Huffman_Tree::Build_Huffman_Tree(){
    while(!all_nodes.empty()){
        Node* minimal_node = Pop_Node();
        if(all_nodes.empty()){
            root_node = minimal_node;
            return ;
        }
        else{
            Node* second_minimal = Pop_Node();
            int sum = minimal_node->counts + second_minimal->counts;
            all_nodes.push(new Node{'\0', sum, minimal_node, second_minimal});
        }
    }
}

void Huffman_Tree::Print_Code_Table(){
    if(root_node == nullptr){
        cout << "This Huffman Tree is empty!" << endl;
        return ;
    }
    queue<char> route;
    Traversal(root_node, route);
}

void Huffman_Tree::Traversal(Node* current, queue<char> route){
    if(current->left != nullptr){
        queue<char> left_route = route;
        left_route.push('0');
        Traversal(current->left, left_route);
    }
    if(current->right != nullptr){
        queue<char> right_route = route;
        right_route.push('1');
        Traversal(current->right, right_route);
    }
    if(current->left == current->right){
        // Leaf node
        cout << "Character: " << current->character << ", Counts: " << current->counts << ", Code: ";
        while(!route.empty()){
            char c = route.front();
            cout << c;
            route.pop();
        }
        cout << endl;
    }
}

int main()
{
    Huffman_Tree code;
    code.Insert('A',67);
    code.Insert('B',152);
    code.Insert('C',92);
    code.Insert('D',263);
    code.Insert('E',128);
    code.Insert('F',86);
    code.Insert('G',20);
    code.Insert('H',36);
    code.Build_Huffman_Tree();
    code.Print_Code_Table();

    return 0;
}
