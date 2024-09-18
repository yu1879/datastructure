#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

template<typename T1, typename T2>
struct Data{
    T1 Key;
    T2 Value;
};

// Balance["Rallod"]
template<typename T1, typename T2>
class Unordered_Map{
    private:
        int len;
        Data<T1,T2>* Pointer;
        int Hash_Func_Div(T1);
        int Hash_Func_Mul(T1);
    public:
        T2& operator[](T1);
        Unordered_Map(int = 128);
};

template<typename T1, typename T2>
Unordered_Map<T1,T2>::Unordered_Map(int m){
    len = m;
    Pointer = (Data<T1,T2>*) malloc(sizeof(Data<T1,T2>)*len);
}

template<typename T1, typename T2>
T2& Unordered_Map<T1,T2>::operator[](T1 input){
    int index = Hash_Func_Mul(input);
    Pointer[index].Key = input;
    return Pointer[index].Value;
}


template<typename T1, typename T2>
int Unordered_Map<T1,T2>::Hash_Func_Div(T1 input){
    long long int sum = 0;
    for(char c:input){
        sum += c;
    }
    return sum % len;
}

template<typename T1, typename T2>
int Unordered_Map<T1,T2>::Hash_Func_Mul(T1 input){
    long long int sum = 0;
    double c = (sqrt(5)-1)/2.0;
    int tmp = 1;
    for(char c:input){
        sum += tmp * c;
        tmp *= 256;
    }
    // get fraction of c*sum
    double frac = c*sum - (int) (c*sum);
    int index = frac * len;
    return index;
}

int main()
{
    Unordered_Map<string,int> balance;

    balance["Mick"] = 50;
    balance["John"] = 100;

    cout << balance["Mick"];


    return 0;
}
