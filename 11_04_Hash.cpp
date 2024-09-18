#include <iostream>
#include <math.h>
#include <vector>
#include <list>
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
        int amount;
        int len;
        vector<list<Data<T1, T2>>> data;
        int Hash_Func_Div(T1);
        int Hash_Func_Mul(T1);
        void Rehashing();
    public:
        void Print();
        T2& operator[](T1);
        Unordered_Map(int = 128);
};

template<typename T1, typename T2>
void Unordered_Map<T1,T2>::Print(){
    for(int i=0;i<data.size();i++){
        // data[i]: linked list
        cout << i << "-th:";
        for(auto iter = data[i].begin();iter!=data[i].end();iter++){
            T1 key = (*iter).Key;
            T2 value = (*iter).Value;
            cout << "{" << key << "," << value << "}";
        }
        cout << endl;
    }
}

template<typename T1, typename T2>
void Unordered_Map<T1,T2>::Rehashing(){
    len *= 2;
    vector<list<Data<T1, T2>>> new_data(len);
    for(int i=0;i<data.size();i++){
        // data[i]: linked list
        for(auto iter = data[i].begin();iter!=data[i].end();iter++){
            T1 key = (*iter).Key;
            T2 value = (*iter).Value;
            int index = Hash_Func_Mul(key);
            new_data[index].push_back(Data<T1, T2>{key, value});
        }
    }
    data = new_data;
}

template<typename T1, typename T2>
Unordered_Map<T1,T2>::Unordered_Map(int m){
    amount = 0;
    len = m;
    data.resize(m);
}

template<typename T1, typename T2>
T2& Unordered_Map<T1,T2>::operator[](T1 input){
    int index = Hash_Func_Mul(input);
    // data[index]: linked_list
    for(auto iter = data[index].begin();iter!=data[index].end();iter++){
        if((*iter).Key == input){
            return (*iter).Value;
        }
    }
    amount++;
    if(amount / len > 5){
        Rehashing();
        int index = Hash_Func_Mul(input);
    }
    data[index].push_back(Data<T1, T2>{input, 0});
    return data[index].back().Value;
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
    Unordered_Map<string,int> balance(1);

    balance["Mick"] = 50;
    balance["John"] = 60;
    balance["Rallod"] = 70;
    balance["David"] = 80;
    balance["Daphlene"] = 90;

    balance.Print();

    balance["Wang"] = 100;
    balance.Print();

    cout << balance["Mick"] << endl;
    cout << balance["John"] << endl;


    return 0;
}
