#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

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
};

template <typename T>
Linked_List<T>::Linked_List(){
    First = nullptr;
}

#endif // LINKED_LIST_H_INCLUDED
