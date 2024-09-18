#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class Course{
    template<class T2> friend istream& operator>>(istream&, Course<T2>&);
    template<class T2> friend ostream& operator<<(ostream&, Course<T2>&);
    private:
        string lecturer;
        int student_number;
        T *score;
    public:
        void set_lecturer(string);
        string get_lecturer();
        void set_student_number(int);
        int get_student_number();
        void set_score_list(T*);
        T* get_score_list();
        float average();
        Course(string = "unknown",int = 0);
        ~Course();
        T operator[](int);
};

template<class T>
void Course<T>::set_lecturer(string name){
    lecturer = name;
}
template<class T>
string Course<T>::get_lecturer(){
    return lecturer;
}
template<class T>
void Course<T>::set_student_number(int n){
    student_number = n;
}
template<class T>
int Course<T>::get_student_number(){
    return student_number;
}
template<class T>
void Course<T>::set_score_list(T* p){
    score = p;
}
template<class T>
T* Course<T>::get_score_list(){
    return score;
}
template<class T>
float Course<T>::average(){
    float sum = 0;
    for(int i=0;i<student_number;i++){
        sum += *(score+i);
    }
    sum /= student_number;
    return sum;
}
template<class T>
Course<T>::Course(string name,int number){
    lecturer = name;
    student_number = number;
    if(number!=0)
        score = (float*) calloc(number,sizeof(float));
}
template<class T>
Course<T>::~Course(){
    cout << "Course finished!" << endl;
    free(score);
}
template<class T>
ostream& operator<<(ostream& os, Course<T>& c){
    os << "Lecturer:" << c.lecturer << endl;
    os << "Student number:" << c.student_number << endl;

    for(int i=0;i<c.student_number;i++){
        os << i+1 << "-th:" << *(c.score+i) << endl;
    }
    return os;
}
template<class T>
istream& operator>>(istream& is, Course<T>& c){
    cout << "Please enter lecturer and number of students:" << endl;
    is >> c.lecturer >> c.student_number;
    cout << "Please enter " << c.student_number << " scores:" << endl;
    for(int i=0;i<c.student_number;i++){
        is >> *(c.score+i);
    }
    return is;
}
template<class T>
T Course<T>::operator[](int index){
    return *(score+index);
}


#endif // COURSE_H_INCLUDED
