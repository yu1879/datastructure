#include <iostream>
#include <queue>

using namespace std;

template<typename T>
struct Node{
    int index;
    T data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
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
        Node<T>* Left_Most(Node<T>*);
        Node<T>* Right_Most(Node<T>*);
        Node<T>* Predecessor(Node<T>*);
        Node<T>* Successor(Node<T>*);
};

template<typename T>
bool Binary_Tree<T>::Delete(int target){
    Node<T>* delete_node = Search(target);

    if(delete_node == nullptr) return false;

    // Case 1: delete_node is a leaf node
    if(delete_node->left == nullptr && delete_node->right == nullptr){
        if(delete_node == root){
            root = nullptr;
        }
        if(delete_node == delete_node->parent->left){
            delete_node->parent->left = nullptr;
        }
        else{
            delete_node->parent->right = nullptr;
        }
        delete delete_node;
    }
    // Case 3: delete_node has 2 child node
    else if(delete_node->left != nullptr && delete_node->right != nullptr){
        // Use successor to replace delete_node
        Node<T>* successor = Left_Most(delete_node->right);
        int tmp1 = successor->index;
        T tmp2 = successor->data;
        // successor must has 0 or 1 child
        // 0 left 0 right
        // 0 left 1 right
        // 1 left 1 right -> voilate
        Delete(successor->index);
        delete_node->index = tmp1;
        delete_node->data = tmp2;
    }
    // Case 2: delete_node has a child node
    else{
        Node<T>* child = (delete_node->left != nullptr)?delete_node->left:delete_node->right;
        if(root == delete_node){
            root = child;
        }
        if(delete_node == delete_node->parent->left){
            delete_node->parent->left = child;
        }
        else{
            delete_node->parent->right = child;
        }
        delete delete_node;
    }
    return true;
}


template<typename T>
Node<T>* Binary_Tree<T>::Left_Most(Node<T>* node){
    if(node == nullptr)
        return nullptr;
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

template<typename T>
Node<T>* Binary_Tree<T>::Right_Most(Node<T>* node){
    if(node == nullptr)
        return nullptr;
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}

template<typename T>
Node<T>* Binary_Tree<T>::Predecessor(Node<T>* node){
    if(node->left != nullptr)
        return Right_Most(node->left);

    Node<T>* current = node->parent;
    while(current != nullptr && node == current->left){
        node = current;
        current = current->parent;
    }
    return current;
}

template<typename T>
Node<T>* Binary_Tree<T>::Successor(Node<T>* node){
    if(node->right != nullptr)
        return Left_Most(node->right);

    Node<T>* current = node->parent;
    while(current != nullptr && node == current->right){
        node = current;
        current = current->parent;
    }
    return current;
}

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
        root = new Node<T>{target, value, nullptr, nullptr, nullptr};
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
                current->left = new Node<T>{target, value, nullptr, nullptr, current};
                return true;
            }
            current = current->left;
        }
        else{
            // Go to right
            if(current->right == nullptr){
                current->right = new Node<T>{target, value, nullptr, nullptr, current};
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

    tree.Delete(58);

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

    cout << "Left most of 24:" << tree.Left_Most(tree.Search(24))->index << endl;
    cout << "Right most of 24:" << tree.Right_Most(tree.Search(24))->index << endl;
    cout << "Successor of 55:" << tree.Successor(tree.Search(55))->index << endl;
    cout << "Predecessor of 82:" << tree.Predecessor(tree.Search(82))->index << endl;

    return 0;
}
