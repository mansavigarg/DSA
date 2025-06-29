#include<iostream>
using namespace std;

class Human{
    public:
    string name;    

    void display(){
        cout << "My name is " << name << endl;
    }
};
class Engineer: public virtual Human{
    public:
    string specilization;

    void work(){
        cout << "I am in " << specilization << endl;
    }
};

class Youtuber: public virtual Human{
    public:
    int subscribers;

    void contentcreator(){
        cout << "I have " << subscribers << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber{
    public:
    int salary;

    CodeTeacher(string name, string specilization, int subscribers, int salary){
        this->name = name;
        this->specilization = specilization;
        this->subscribers = subscribers;
        this->salary = salary;
    }

};

int main(){
    CodeTeacher A1("Manu", "CSE", 234543, 33);
    A1.display();

    return 0;
}