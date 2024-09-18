#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<typename T>
class Vector{
    private:
        T* Pointer;
        int Capacity;
        int Len;
    public:
        class Iterator{
            private:
                T* iter;
            public:
                Iterator(T* = nullptr);
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
                bool operator>(Iterator);
                bool operator<(Iterator);
                bool operator>=(Iterator);
                bool operator<=(Iterator);
                void operator=(Iterator);
                int operator-(Iterator);
                Iterator operator+(int);
                Iterator operator-(int);
                T& operator*();
        };
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
        void Insert(Iterator, T);
        void Erase(Iterator);
        void Erase(Iterator, Iterator);
        void Clear();
        void Reserve(int);
        void Resize(int);
        Iterator Begin();
        Iterator End();
};

template<typename T>
typename Vector<T>::Iterator Find(Vector<T> v, T target){
    for(auto iter = v.Begin();iter!=v.End();iter++){
        if(*iter == target)
            return iter;
    }
    return v.End();
}


template<typename T>
typename Vector<T>::Iterator Remove(Vector<T> v, T target){
    int counts = 0;
    for(auto iter = v.Begin();iter!=v.End();iter++){
        if(*iter == target)
            continue;
        *(v.Begin()+counts) = *iter;
        counts++;
    }
    for(auto iter = (v.Begin()+counts);iter!=v.End();iter++){
        *iter = target;
    }
    return v.Begin()+counts;
}

template<typename T>
Vector<T>::Iterator::Iterator(T* pointer){
    iter = pointer;
}

template<typename T>
void Vector<T>::Iterator::operator++(){
    // ++Iterator
    iter++;
}

template<typename T>
void Vector<T>::Iterator::operator--(){
    // --Iterator
    iter--;
}

template<typename T>
void Vector<T>::Iterator::operator++(int){
    // Iterator++
    iter++;
}


template<typename T>
void Vector<T>::Iterator::operator--(int){
    // Iterator--
    iter--;
}

template<typename T>
bool Vector<T>::Iterator::operator==(Iterator iter2){
    return iter == iter2.iter;
}

template<typename T>
bool Vector<T>::Iterator::operator!=(Iterator iter2){
    return iter != iter2.iter;
}

template<typename T>
bool Vector<T>::Iterator::operator>(Iterator iter2){
    return iter > iter2.iter;
}


template<typename T>
bool Vector<T>::Iterator::operator<(Iterator iter2){
    return iter < iter2.iter;
}

template<typename T>
bool Vector<T>::Iterator::operator>=(Iterator iter2){
    return iter >= iter2.iter;
}

template<typename T>
bool Vector<T>::Iterator::operator<=(Iterator iter2){
    return iter <= iter2.iter;
}

template<typename T>
void Vector<T>::Iterator::operator=(Iterator iter2){
    iter = iter2.iter;
}

template<typename T>
T& Vector<T>::Iterator::operator*(){
    return *iter;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Begin(){
    Iterator result(Pointer);
    return result;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::End(){
    Iterator result(Pointer + Len);
    return result;
}

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
void Vector<T>::Insert(Iterator iter2, T data){
    if(iter2>End())
        return;
    if(iter2 < Begin())
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
    auto tmp = iter2;
    for(iter2=End();iter2>=tmp;iter2--){
        *(iter2+1) = *(iter2);
    }
    *(tmp) = data;
    Len++;
}

template<typename T>
void Vector<T>::Erase(Iterator iter2){
    if(Empty())
        return ;
    if(iter2 >= End())
        return ;
    if(iter2 < Begin())
        return ;
    // 1 2 3 4 5
    // delete index 1
    // 1 3 4 5 5
    for(iter2++;iter2<End();iter2++){
        *(iter2-1) = *(iter2);
    }
    Len--;
}

template<typename T>
void Vector<T>::Erase(Iterator start, Iterator finish){
    if(Empty())
        return ;
    if(finish >= End())
        return ;
    if(finish <= start)
        return ;
    if(start < Begin())
        return ;
    // 1 2 3 4 5
    // delete index 1, 2
    // 1 4 5 4 5
    auto tmp = finish;
    for(;tmp<End();tmp++){
        *(tmp-(finish-start)) = *tmp;
    }
    Len -= finish-start;
}

template<typename T>
int Vector<T>::Iterator::operator-(Iterator iter2){
    return (iter - iter2.iter);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int offset){
    Iterator result(iter+offset);
    return result;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int offset){
    Iterator result(iter-offset);
    return result;
}


template<typename T>
void Vector<T>::Clear(){
    free(Pointer);
    Len = 0;
    Capacity = 0;
    Pointer = nullptr;
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
