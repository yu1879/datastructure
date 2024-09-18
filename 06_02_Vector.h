#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<typename T>
class Vector{
    private:
        T* Pointer;
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
        void Pop_Back();
};

template<typename T>
Vector<T>::Vector(int length){
    if(length == 0){
        Pointer = nullptr;
        // or Pointer = 0
        Len = 0;
    }
    else{
        Len = length;
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
    Len++;
    T* tmp = (T*) malloc(sizeof(T)*Len);
    for(int i=0;i<Len-1;i++){
        *(tmp+i) = *(Pointer+i);
    }
    *(tmp+Len-1) = data;
    free(Pointer);
    Pointer = tmp;
}

template<typename T>
void Vector<T>::Pop_Back(){
    Len--;
    T* tmp = (T*) malloc(sizeof(T)*Len);
    for(int i=0;i<Len;i++){
        *(tmp+i) = *(Pointer+i);
    }
    free(Pointer);
    Pointer = tmp;
}
#endif // VECTOR_H_INCLUDED
