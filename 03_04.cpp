#include <iostream>

using namespace std;

class Person{
    friend void print(Person& p);
    private:
        string name;
        float height;
        float weight;
    public:
        void set_name(string);
        string get_name();
        void set_height(float);
        float get_height();
        void set_weight(float);
        float get_weight();
        void print();
        Person(string="anonymous",float=0,float=0);
        ~Person();
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

void print(Person& p){
    cout << "Name: " << p.name << endl;
    cout << "Height: " << p.height << endl;
    cout << "Weight: " << p.weight << endl;
}

Person::Person(string n, float h, float w){
    name = n;
    height = h;
    weight = w;
}

Person::~Person(){
    cout << "Object was destructed!" << endl;
}
int main()
{
    Person p1;
    Person p2("Mick",168,60);
    // p.set_name("LKM");
    // p.set_height(168);
    // p.set_weight(60);

    // p.print();
    print(p1);
    print(p2);

    return 0;
}
