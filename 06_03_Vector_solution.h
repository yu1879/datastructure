#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<typename T>
class Vector{
    private:
        T* Pointer;
        int Capacity;
        int Len;
    public:
        Vector(int=0);
        ~Vector();
        T Front();
        T Back();
        T& At(int);
        T& operator[](int);
        int Size();
        bool Empty();
        void Push_Back(T);
        void Push_Back_Old(T);
        void Pop_Back();
        void Insert(int, T);
        void Erase(int);
        void Erase(int, int);
        void Clear();
        void Reserve(int);
        void Resize(int);
};

template<typename T>
Vector<T>::Vector(int length){
    if(length == 0){
        Pointer = nullptr;
        // or Pointer = 0
        Len = 0;
        Capacity = 0;
    }
    else{
        Len = length;
        Capacity = length;
        Pointer = (T*) calloc(length, sizeof(T));
    }
}

template<typename T>
Vector<T>::~Vector(){
    free(Pointer);
}

template<typename T>
T Vector<T>::Front(){
    return *Pointer;
}

template<typename T>
T Vector<T>::Back(){
    return *(Pointer + Len - 1);
}


template<typename T>
T& Vector<T>::At(int index){
    return *(Pointer+index);
}

template<typename T>
T& Vector<T>::operator[](int index){
    return *(Pointer+index);
}

template<typename T>
int Vector<T>::Size(){
    return Len;
}

template<typename T>
bool Vector<T>::Empty(){
    return Len == 0;
}

template<typename T>
void Vector<T>::Push_Back(T data){
    if(Len == Capacity){
        if(Capacity == 0)
            Reserve(1);
        else
            Reserve(Capacity * 2);
    }
    *(Pointer+Len) = data;
    Len++;
}

template<typename T>
void Vector<T>::Pop_Back(){
    if(Empty())
        return ;
    Len--;
}

template<typename T>
void Vector<T>::Insert(int index, T data){
    if(index > Size())
        return;
    if(index < 0)
        return;
    if(Len == Capacity){
        if(Capacity == 0)
            Reserve(1);
        else
            Reserve(Capacity * 2);
    }
    // 1 2 3 4 5
    // insert 100 to index 0
    // 100 1 2 3 4 5
    for(int i=Len-1;i>=index;i--){
        *(Pointer+i+1) = *(Pointer+i);
    }
    *(Pointer+index) = data;
    Len++;
}

template<typename T>
void Vector<T>::Erase(int index){
    if(Empty())
        return ;
    if(index >= Size())
        return ;
    if(index < 0)
        return ;
    // 1 2 3 4 5
    // delete index 1
    // 1 3 4 5 5
    for(int i=index+1;i<Len;i++){
        *(Pointer+i-1) = *(Pointer+i);
    }
    Len--;
}

template<typename T>
void Vector<T>::Erase(int start, int finish){
    if(Empty())
        return ;
    if(finish >= Size())
        return ;
    if(finish <= start)
        return ;
    if(start < 0)
        return ;
    // 1 2 3 4 5
    // delete index 1, 2
    // 1 4 5 4 5
    for(int i=finish;i<Len;i--){
            *(Pointer+i-(finish-start)) = *(Pointer+i+1);
    }
    Len -= finish-start;
}

template<typename T>
void Vector<T>::Clear(){
    free(Pointer);
    Len = 0;
    Capacity = 0;
}

template<typename T>
void Vector<T>::Reserve(int N){
    if(N<Len)
        return ;
    Capacity = N;
    T* tmp = (T*) malloc(sizeof(T)*Capacity);
    for(int i=0;i<Len;i++){
        *(tmp+i) = *(Pointer+i);
    }
    free(Pointer);
    Pointer = tmp;
}

template<typename T>
void Vector<T>::Resize(int N){
    if(N < 0)
        return ;
    if(N <= Capacity)
        Len = N;
}


template<typename T>
void Vector<T>::Push_Back_Old(T data){
    Len++;
    T* tmp = (T*) malloc(sizeof(T)*Len);
    for(int i=0;i<Len-1;i++){
        *(tmp+i) = *(Pointer+i);
    }
    *(tmp+Len-1) = data;
    free(Pointer);
    Pointer = tmp;
}

#endif // VECTOR_H_INCLUDED
