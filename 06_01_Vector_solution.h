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

#endif // VECTOR_H_INCLUDED
