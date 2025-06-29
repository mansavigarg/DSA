#include<iostream>
using namespace std;

class Human{

    protected:
    string name;
    int age;

    public:
    void work(){
        cout << "I am working ." << endl;
    }

    // void display(){
    //     cout << name << " " << age << " " << endl;
    // }
};

class Student: public Human {
    int roll_num, fees;

    public:
    Student(string name, int age, int roll_num, int fees){
        this->name = name;
        this->age = age;
        this->roll_num = roll_num;
        this->fees = fees;
    }
};

class Teacher: public Human {
    int salary;

    public:
    Teacher(string name, int age, int salary){
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void display(){
        cout << name << " " << age << " " << salary << " " << endl;
    }
};

int main(){
    Student A1("manu", 28,43,66);
    A1.work();
    Teacher A2("jdkssa",34,345);
    A2.display();
    
    return 0;
}