#ifndef CIRCULAR_LINKED_LIST_H_INCLUDED
#define CIRCULAR_LINKED_LIST_H_INCLUDED

#include <iostream>
#include "Function.h"

using namespace std;

template <typename T>
struct Node{
    T Data;
    Node*  Prev;
    Node*  Next;
};

template <typename T>
class Linked_List{
    private:
        Node<T>* Head;
        // Node<T>* Tail;
        int Len;
    public:
        class Iterator{
            friend Linked_List;
            private:
                Node<T>* iter;
            public:
                Iterator(Node<T>* = nullptr);
                void operator++();
                // ++Iterator
                void operator--();
                // --Iterator
                void operator++(int);
                // Iterator++
                void operator--(int);
                // Iterator--
                bool operator==(Iterator);
                bool operator!=(Iterator);
                void operator=(Iterator);
                /*
                Iterator operator+(int);
                Iterator operator-(int);
                */
                T& operator*();
        };
        Linked_List();
        /*
        void Print_List();
        int Search_List(T);
        void Push_Front(T);
        void Pop_Front();
        void Pop_Back();
        void Clear();
        void Reverse();
        void Insert(Iterator, const T&);
        void Erase(Iterator);
        void Remove(T);
        */
        void Push_Back(T);
        void Rotate(int);
        Iterator Begin();
        /*
        Iterator End();
        Iterator Head_Iter();
        */
        // Iterator Tail_Iter();
    // template<typename T2> friend typename Linked_List<T2>::Iterator Find(Linked_List<T2>, T2);
};

/*
template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Head_Iter(){
    return Iterator(Head);
}

template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Tail_Iter(){
    return Iterator(Tail);
}
template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::End(){
    return Iterator(nullptr);
}
*/

template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Begin(){
    return Iterator(Head);
}

/*
template<typename T>
void Linked_List<T>::Insert(Iterator it, const T& value){
    // A B, B is provided by user = it
    // A C B
    if(it == Begin()){
        Push_Front(value);
        return;
    }
    if(it == End() || it == Iterator(Tail)){
        Push_Back(value);
        return;
    }
    Node<T> *new_node = new Node<T>{value, it.iter->Prev, it.iter};
    it.iter->Prev->Next = new_node; // A -> Next = C
    it.iter->Prev = new_node; // B -> Prev = C
}

template<typename T>
void Linked_List<T>::Erase(Iterator it){
    // A B C, B is provided by user = it
    // A C
    // TODO: Cannot use to erase front.
    // TODO: Cannot use to erase tail.
    if(it == Begin()){
        Pop_Front();
        return;
    }
    if(it == End() || it == Iterator(Tail)){
        Pop_Back();
        return;
    }
    it.iter->Prev->Next = it.iter->Next; // A -> Next = C
    it.iter->Next->Prev = it.iter->Prev; // C -> Prev = A
    delete it.iter;
}

template<typename T>
void Linked_List<T>::Remove(T value){
    for(auto iter = Begin(); iter!=End();iter++){
        // A B C, Delete B
        // A C, let iterator = A
        if(*iter == value){
            if(iter == Begin()){
                Pop_Front();
            }
            else{
                auto tmp = iter;
                tmp--;
                Erase(iter);
                iter = tmp;
            }
        }
    }
}

template<typename T>
typename Linked_List<T>::Iterator Find(Linked_List<T> List, T data){
    typename Linked_List<T>::Iterator null_iter(nullptr);
    // Empty list
    if(List.Begin() == null_iter){
        return null_iter;
    }

    auto current = List.Begin();
    while(current != null_iter){
        if(*current == data)
            return current;
        current++;
    }
    return current; // Not found.
}
*/

template<typename T>
Linked_List<T>::Iterator::Iterator(Node<T>* pointer){
    iter = pointer;
}

template<typename T>
void Linked_List<T>::Iterator::operator++(){
    // ++Iterator
    if(iter != nullptr){
        iter = iter->Next;
    }
}

template<typename T>
void Linked_List<T>::Iterator::operator--(){
    // --Iterator
    if(iter != nullptr){
        iter = iter->Prev;
    }
}

template<typename T>
void Linked_List<T>::Iterator::operator++(int){
    // Iterator++
    if(iter != nullptr){
        iter = iter->Next;
    }
}


template<typename T>
void Linked_List<T>::Iterator::operator--(int){
    // Iterator--
    if(iter != nullptr){
        iter = iter->Prev;
    }
}

template<typename T>
bool Linked_List<T>::Iterator::operator==(Iterator iter2){
    return iter == iter2.iter;
}

template<typename T>
bool Linked_List<T>::Iterator::operator!=(Iterator iter2){
    return iter != iter2.iter;
}

template<typename T>
void Linked_List<T>::Iterator::operator=(Iterator iter2){
    iter = iter2.iter;
}

template<typename T>
T& Linked_List<T>::Iterator::operator*(){
    return iter->Data;
}
/*
template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Iterator::operator+(int offset){
    Iterator result(iter);
    for(int i=0;i<offset;i++){
        if(result->iter == nullptr)
            return result;
        result->iter = result->iter->Next;
    }
    return result;
}

template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Iterator::operator-(int offset){
    Iterator result(iter);
    for(int i=0;i<offset;i++){
        if(result->iter == nullptr)
            return result;
        result->iter = result->iter->Prev;
    }
    return result;
}

template <typename T>
void Linked_List<T>::Reverse(){
    // Empty list
    if(Head == nullptr)
        return ;
    // Only one data in this list
    if(Head == Tail)
        return ;
    Node<T>* previous = nullptr;
    Node<T>* currrent = Head;
    Node<T>* preceding = Head->Next;
    Tail = Head;

    while(preceding != nullptr){
        currrent->Next = previous;
        currrent->Prev = preceding;
        previous = currrent;
        currrent = preceding;
        preceding = preceding->Next;
    }
    currrent->Next = previous;
    currrent->Prev = preceding;
    Head = currrent;
}

template <typename T>
void Linked_List<T>::Clear(){
    Node<T>* currrent;
    while(Head != nullptr){
        currrent = Head;
        Head = Head->Next;
        delete currrent;
    }
    Tail = nullptr;
}
*/

template <typename T>
void Linked_List<T>::Push_Back(T value){
    if(Head == nullptr){
        // Empty;
        Head = new Node<T>{value, nullptr, nullptr};
        Head->Next = Head->Prev = Head;
    }
    else{
        // Tail: Head->Prev
        Node<T> *new_node = new Node<T>{value, Head->Prev, Head};
        Head->Prev->Next = new_node;
        Head->Prev = new_node;
    }
    Len++;
}

template <typename T>
void Linked_List<T>::Rotate(int offset){
    if(Head == nullptr)
        return;
    offset = offset % Len;
    for(int i=0;i<offset;i++){
        Head = Head->Next;
    }
}
/*
template <typename T>
void Linked_List<T>::Pop_Back(){
    // Empty
    if(Head == nullptr)
        return ;
    // Only one data in this list
    if(Head == Tail){
        delete Tail;
        Head = Tail = nullptr;
        return ;
    }

    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = nullptr;
}

template <typename T>
void Linked_List<T>::Push_Front(T value){
    if(Head == nullptr){
        // Empty;
        Node<T>* new_node = new Node<T>{value, nullptr, nullptr};
        // new_node->Data = value;
        // new_node->Next = Head;
        Head = new_node;
        Tail = new_node;
    }
    else{
        Head->Prev = new Node<T>{value, nullptr, Head};
        Head = Head->Prev;
    }
}

template <typename T>
void Linked_List<T>::Pop_Front(){
    if(Head == nullptr){
        return ;
    }
    // Only one data in this list
    if(Head == Tail){
        delete Head;
        Head = Tail = nullptr;
        return ;
    }

    Head = Head->Next;
    delete Head->Prev;
    Head->Prev = nullptr;
}
*/

template <typename T>
Linked_List<T>::Linked_List(){
    Head = nullptr;
    Len = 0;
    // Tail = nullptr;
}

/*
template <typename T>
void Linked_List<T>::Print_List(){
    if(Head == nullptr){
        cout << "This list is empty!" << endl;
        return ;
    }
    Node<T>* current = Head;
    cout << "Data:";
    while(current->Next != 0){
        cout << current->Data << " ";
        current = current->Next;
    }
    cout << current->Data << endl;
}

template <typename T>
int Linked_List<T>::Search_List(T target){
    if(Head == nullptr)
        return -1;
    int index = 0;
    Node<T>* current = Head;
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
*/

#endif // CIRCULAR_LINKED_LIST_H_INCLUDED
