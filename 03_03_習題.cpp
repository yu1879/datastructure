#include <iostream>

using namespace std;

class Course{
    string lecturer;
    int student_number;
    float *score;

    void set_lecturer(string);
    string get_lecturer();
    void set_student_number(int);
    int get_student_number();
    void set_score_list(float*);
    float* get_score_list();
    float average();
};

void Course::set_lecturer(string name){
    lecturer = name;
}

string Course::get_lecturer(){
    return lecturer;
}

void Course::set_student_number(int n){
    student_number = n;
}

int Course::get_student_number(){
    return student_number;
}

void Course::set_score_list(float* p){
    score = p;
}

float* Course::get_score_list(){
    return score;
}

float Course::average(){
    float sum = 0;
    for(int i=0;i<student_number;i++){
        sum += *(score+i);
    }
    sum /= student_number;
    return sum;
}

int main()
{

    return 0;
}
