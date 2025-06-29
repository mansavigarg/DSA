#include<iostream>
using namespace std;

class Student {
    public:
    string name;
    int age, roll_num;
    string grade;

    //$ Function Setter
    public:
    void setname(string s){

        //@ can put several checks here
        if(s.length() == 0){
            cout << "Invalid name";
            return;
        }
        name = s;
    }
    void setage(int a){
        if(age<0 || age>100){
            cout << "Invalid age";
            return;
        }
        age = a;
    }
    void setroll_num(int r){
        roll_num = r;
    }
    void setgrade(string s){
        grade = s;
    }
    
    //$ Function Getter
    void getname(){
        cout << name << endl;
    }
    void getage(){
        cout << age << endl;
    }
    void getroll_num(){
        cout << roll_num << endl;
    }
    void getgrade(){
        cout << grade << endl;
    }
    // we can also return the value
    int get_roll_num(){
        return roll_num;
    }
    string get_grade(int pin){
        if(pin == 123)
        return grade;

        return "teri bhens ki tan tana tan";
    }

};

int main(){
    Student s1;
    s1.setname("Mansavi");
    s1.setage(21);
    s1.setroll_num(244);
    s1.setgrade("A++");

    s1.getname();
    s1.getage();
    s1.getroll_num();
    s1.getgrade();
    cout << s1.get_roll_num() << endl;

    cout << s1.get_grade(123) << endl;
    cout << s1.get_grade(12) << endl;


    return 0;
}