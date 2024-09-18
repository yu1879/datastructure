#include <iostream>

using namespace std;

class Person{
    string name;
    float height;
    float weight;

    void set_name(string);
    string get_name();
    void set_height(float);
    float get_height();
    void set_weight(float);
    float get_weight();
    void print();
};

void Person::set_name(string n){
    name = n;
}

string Person::get_name(){
    return name;
}

void Person::set_height(float n){
    height = n;
}

float Person::get_height(){
    return height;
}

void Person::set_weight(float n){
    weight = n;
}

float Person::get_weight(){
    return weight;
}

void Person::print(){
    cout << "Name: " << name << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
}

int main()
{

    return 0;
}
