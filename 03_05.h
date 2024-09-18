#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
class Person{
    template<typename T2> friend ostream& operator<<(ostream&, Person<T2>&);
    template<typename T2> friend istream& operator>>(istream&, Person<T2>&);
    private:
        string name;
        T height;
        T weight;
    public:
        void set_name(string);
        string get_name();
        void set_height(T);
        T get_height();
        void set_weight(T);
        T get_weight();
        void print();
        Person(string="anonymous",T=0,T=0);
        ~Person();
        T operator+(Person&);
};

template<typename T>
void Person<T>::set_name(string n){
    name = n;
}

template<typename T>
string Person<T>::get_name(){
    return name;
}

template<typename T>
void Person<T>::set_height(T n){
    height = n;
}

template<typename T>
T Person<T>::get_height(){
    return height;
}
template<typename T>
void Person<T>::set_weight(T n){
    weight = n;
}

template<typename T>
T Person<T>::get_weight(){
    return weight;
}

template<typename T>
void print(Person<T>& p){
    cout << "Name: " << p.name << endl;
    cout << "Height: " << p.height << endl;
    cout << "Weight: " << p.weight << endl;
}

template<typename T>
Person<T>::Person(string n, T h, T w){
    name = n;
    height = h;
    weight = w;
}
template<typename T>
Person<T>::~Person(){
    cout << "Object was destructed!" << endl;
}
template<typename T>
T Person<T>::operator+(Person<T>& p){
    return weight + p.weight;
}

template<typename T>
ostream& operator<<(ostream& os, Person<T>& p){
    os << "Name: " << p.name << endl;
    os << "Height: " << p.height << endl;
    os << "Weight: " << p.weight << endl;
    return os;
}

template<typename T>
istream& operator>>(istream& is, Person<T>& p){
    is >> p.name >> p.height >> p.weight;
    return is;
}

#endif // PERSON_H_INCLUDED
