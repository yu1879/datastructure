#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T Data;
    Node*  Next;
};

template <typename T>
class Linked_List{
    private:
        Node<T>* First;
    public:
        Linked_List();
        void Print_List();
        int Search_List(T);
        void Push_Front(T);
        void Pop_Front();
        void Push_Back(T);
        void Pop_Back();
        void Clear();
        void Reverse();
};

template <typename T>
void Linked_List<T>::Reverse(){
    // Empty list
    if(First == nullptr)
        return ;
    // Only one data in this list
    if(First->Next == nullptr)
        return ;
    Node<T>* previous = nullptr;
    Node<T>* currrent = First;
    Node<T>* preceding = First->Next;

    while(preceding != nullptr){
        currrent->Next = previous;
        previous = currrent;
        currrent = preceding;
        preceding = preceding->Next;
    }
    currrent->Next = previous;
    First = currrent;
}

template <typename T>
void Linked_List<T>::Clear(){
    Node<T>* currrent;
    while(First != nullptr){
        currrent = First;
        First = First->Next;
        delete currrent;
    }
}

template <typename T>
void Linked_List<T>::Push_Back(T value){
    if(First == nullptr){
        // Push_Front(value);
        Node<T>* new_node = new Node<T>{value, First};
        // new_node->Data = value;
        // new_node->Next = First;
        First = new_node;
    }
    else{
        Node<T>* current = First;
        while(current->Next != nullptr){
            current = current->Next;
        }
        current->Next = new Node<T>{value, nullptr};
    }
}

template <typename T>
void Linked_List<T>::Pop_Back(){
    if(First == nullptr){
        return ;
    }
    else{
        Node<T>* current = First;
        if(current->Next == nullptr){
            // only one data in this linked li
            delete First;
            First = nullptr;
            return ;
        }
        while(current->Next->Next != nullptr){
            current = current->Next;
        }
        // current : Last 2nd node
        // current->Next : Last node
        // current->Next->Next : nullptr
        delete current->Next;
        current->Next = nullptr;
    }
}

template <typename T>
void Linked_List<T>::Push_Front(T value){
    Node<T>* new_node = new Node<T>{value, First};
    // new_node->Data = value;
    // new_node->Next = First;
    First = new_node;
}

template <typename T>
void Linked_List<T>::Pop_Front(){
    if(First == nullptr){
        return ;
    }
    Node<T>* tmp = First;
    First = First -> Next;
    delete tmp;
}

template <typename T>
Linked_List<T>::Linked_List(){
    First = nullptr;
}

template <typename T>
void Linked_List<T>::Print_List(){
    if(First == nullptr){
        cout << "This list is empty!" << endl;
        return ;
    }
    Node<T>* current = First;
    cout << "Data:";
    while(current->Next != 0){
        cout << current->Data << " ";
        current = current->Next;
    }
    cout << current->Data << endl;
}

template <typename T>
int Linked_List<T>::Search_List(T target){
    if(First == nullptr)
        return -1;
    int index = 0;
    Node<T>* current = First;
    while(current->Next != 0){
        if(current->Data == target)
            return index;
        current = current->Next;
        index++;
    }
    if(current->Data == target)
        return index;
    else
        return -1;
}

#endif // LINKED_LIST_H_INCLUDED
