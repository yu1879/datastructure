#include <iostream>
#include <queue>

using namespace std;

template<typename T>
struct Node{
    int index;
    T data;
    Node<T> *left;
    Node<T> *right;
};

template<typename T>
class Binary_Tree{
    public:
        Node<T>* root;
        Binary_Tree();
        void Print(Node<T>);
        bool Insert(int,T);
        Node<T>* Search(int);
        bool Delete(int);
        void Pre_Order(Node<T>*);
        void In_Order(Node<T>*);
        void Post_Order(Node<T>*);
        void Level_Order(Node<T>*);
};

template<typename T>
void Binary_Tree<T>::Pre_Order(Node<T>* node){
    if(node == nullptr)
        return ;
    cout << node->index << " ";
    Pre_Order(node->left);
    Pre_Order(node->right);
}

template<typename T>
void Binary_Tree<T>::In_Order(Node<T>* node){
    if(node == nullptr)
        return ;
    In_Order(node->left);
    cout << node->index << " ";
    In_Order(node->right);
}

template<typename T>
void Binary_Tree<T>::Post_Order(Node<T>* node){
    if(node == nullptr)
        return ;
    Post_Order(node->left);
    Post_Order(node->right);
    cout << node->index << " ";
}

template<typename T>
void Binary_Tree<T>::Level_Order(Node<T>* node){
    queue<Node<T>*> Q;
    Q.push(node);

    while(!Q.empty()){
        Node<T>* current = Q.front();
        Q.pop();
        cout << current->index << " ";
        if(current->left){
            Q.push(current->left);
        }
        if(current->right){
            Q.push(current->right);
        }
    }
}

template<typename T>
Binary_Tree<T>::Binary_Tree(){
    root = nullptr;
}

template<typename T>
void Binary_Tree<T>::Print(Node<T> node){
    cout << "Index: " << node.index << endl;
    cout << "Data: " << node.data << endl;
}

template<typename T>
bool Binary_Tree<T>::Insert(int target,T value){
    if(root == nullptr){
        // This binary tree is empty
        root = new Node<T>{target, value, nullptr, nullptr};
        return true;
    }

    Node<T>* current = root;
    while(true){
        if(current->index == target){
            return false;
        }
        else if(target < current->index){
            // Go to left
            if(current->left == nullptr){
                current->left = new Node<T>{target, value, nullptr, nullptr};
                return true;
            }
            current = current->left;
        }
        else{
            // Go to right
            if(current->right == nullptr){
                current->right = new Node<T>{target, value, nullptr, nullptr};
                return true;
            }
            current = current->right;
        }
    }
}

template<typename T>
Node<T>* Binary_Tree<T>::Search(int target){
    if(root == nullptr)
        return nullptr;

    Node<T>* current = root;
    while(true){
        if(current->index == target){
            return current;
        }
        else if(target < current->index){
            // Go to left
            if(current->left == nullptr){
                return nullptr;
            }
            current = current->left;
        }
        else{
            // Go to right
            if(current->right == nullptr){
                return nullptr;
            }
            current = current->right;
        }
    }
}

int main()
{
    Binary_Tree<string> tree;

    tree.Insert(58, "A");
    tree.Insert(24, "B");
    tree.Insert(97, "C");
    tree.Insert(12, "D");
    tree.Insert(49, "E");
    tree.Insert(82, "F");
    tree.Insert(55, "G");

    cout << "Pre-order:";
    tree.Pre_Order(tree.root);
    cout << endl;

    cout << "In-order:";
    tree.In_Order(tree.root);
    cout << endl;

    cout << "Post-order:";
    tree.Post_Order(tree.root);
    cout << endl;

    cout << "Level-order:";
    tree.Level_Order(tree.root);
    cout << endl;

    return 0;
}
