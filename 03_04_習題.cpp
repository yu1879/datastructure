#include <iostream>
#include <stdlib.h>
using namespace std;

class Course{
    friend void print(Course&);
    private:
        string lecturer;
        int student_number;
        float *score;
    public:
        void set_lecturer(string);
        string get_lecturer();
        void set_student_number(int);
        int get_student_number();
        void set_score_list(float*);
        float* get_score_list();
        float average();
        Course(string = "unknown",int = 0,float* =0);
        ~Course();
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

void print(Course& c){
    cout << "Lecturer:" << c.lecturer << endl;
    cout << "Student number:" << c.student_number << endl;

    for(int i=0;i<c.student_number;i++){
        cout << i+1 << "-th:" << *(c.score+i) << endl;
    }
}

Course::Course(string name,int number,float* score_list){
    lecturer = name;
    student_number = number;
    if(number!=0 && score_list == 0){
        score = (float*) calloc(number,sizeof(float));
    }
    else{
        score = score_list;
    }
}

Course::~Course(){
    cout << "Course finished!" << endl;
    free(score);
}

int main()
{
    // float score[5] = {85,95,60,82,78};
    Course math("LKM", 5);
    // math.set_lecturer("LKM");
    // math.set_student_number(5);
    // math.set_score_list(score);

    print(math);

    return 0;
}
