#include<iostream>
using namespace std;

class Student {
    public:
    string name;
    int age, roll_num;
    string grade;
};

int main(){
    Student s1;
    s1.name = "Mansavi";
    s1.age = 21;
    s1.roll_num = 244;
    s1.grade = "A++";

    cout << s1.name << endl;

    Student s2;
    s2.name = "Shivani";
    s2.age = 21;
    s2.roll_num = 244;
    s2.grade = "A++";

    cout << s2.name << endl;


    return 0;
}