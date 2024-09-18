#include <iostream>

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
};

template<typename T>
Binary_Tree<T>::Binary_Tree(){
    root = nullptr;
}

template<typename T>
void Binary_Tree<T>::Print(Node<T> node){
    cout << "Index: " << node.index << endl;
    cout << "Data: " << node.data << endl;
}


int main()
{

    return 0;
}
