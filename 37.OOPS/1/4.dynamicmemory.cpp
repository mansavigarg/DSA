#include<iostream>
using namespace std;

class Student {
    public:
    string name;
    int age, roll_num;
    string grade;
};

int main(){

    Student *S = new Student;

    (*S).name = "Manu";
    (*S).age = 20;
    (*S).roll_num = 2121;
    (*S).grade = "A++";

    cout << S->name << endl;
    cout << S->age << endl;
    cout << S->roll_num << endl;
    cout << S->grade << endl;
    
    return 0;
}