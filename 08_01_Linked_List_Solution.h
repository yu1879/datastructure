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
};

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
