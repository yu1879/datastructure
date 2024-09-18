#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T Data;
    Node* Next;
};

template <typename T>
class Queue{
    private:
        Node<T>* First;
        Node<T>* Rear;
    public:
        Queue();
        T Front();
        T Back();
        bool Empty();
        int Size();
        void Push(T);
        void Pop();
        void Print_Queue();
};

template <typename T>
Queue<T>::Queue(){
    First = Rear = nullptr;
}

template <typename T>
void Queue<T>::Print_Queue(){
    if(Empty()) cout << "This queue is empty!" << endl;
    else{
        Node<T>* current = First;
        cout << "Queue: ";
        while(current != Rear){
            cout << current->Data << " ";
            current = current->Next;
        }
        cout << current->Data << endl;
    }
}

template <typename T>
T Queue<T>::Front(){
    if(Empty()){
        cout << "Error: This queue is empty!" << endl;
        return 0;
    }
    return First->Data;
}

template <typename T>
T Queue<T>::Back(){
    if(Empty()){
        cout << "Error: This queue is empty!" << endl;
        return 0;
    }
    return Rear->Data;
}

template <typename T>
bool Queue<T>::Empty(){
    return First == nullptr;
}

template <typename T>
int Queue<T>::Size(){
    if(Empty()) return 0;

    int len = 1;
    Node<T>* current = First;
    while(current != Rear){
        current = current->Next;
        len++;
    }
    return len;
}

template <typename T>
void Queue<T>::Push(T value){
    if(Empty()){
        First = Rear = new Node<T>{value, nullptr};
        return ;
    }

    Node<T>* new_node = new Node<T>{value, nullptr};
    Rear->Next = new_node;
    Rear = new_node;
}

template <typename T>
void Queue<T>::Pop(){
    if(Empty())
        return ;

    Node<T>* tmp = First;
    First = First->Next;
    delete tmp;
    if(First == nullptr)
        Rear = nullptr;
}

int main()
{
    int N;
    cout << "Please enter N:";
    cin >> N;

    Queue<int> data;

    for(int i=1;i<=N;i++)
        data.Push(i);

    while(data.Size()>1){
        data.Print_Queue();
        int delete_number = data.Front();
        cout << "Delete card number:" << delete_number << endl;
        data.Pop();
        int move_number = data.Front();
        cout << "Move card number:" << move_number << " from top to bottom." << endl;
        data.Pop();
        data.Push(move_number);
    }

    cout << "Last card: " << data.Front();

    return 0;
}
