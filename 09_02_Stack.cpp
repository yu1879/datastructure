#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

template<typename T>
class Stack_Array{
    private:
        int Capacity;
        int Top_Index;
        T* Pointer;
        void Double_Capacity();
    public:
        Stack_Array(int=0);
        bool Empty();
        int Size();
        T Top();
        void Push(T);
        void Pop();
        void Print_Stack();
};

template<typename T>
Stack_Array<T>::Stack_Array(int len){
    Capacity = len;
    if(len>0){
        Pointer = (T*) malloc(sizeof(T)*len);
    }
    else{
        Pointer = nullptr;
    }
    Top_Index = -1;
}

template<typename T>
void Stack_Array<T>::Print_Stack(){
    cout << "Data:";
    for(int i=0;i<=Top_Index;i++){
        cout << *(Pointer + i) << " ";
    }
    cout << endl;
}

#endif // STACK_H_INCLUDED
