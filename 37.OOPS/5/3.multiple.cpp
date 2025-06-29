#include<iostream>
using namespace std;

class Engineer{
    public:
    string specilization;

    void work(){
        cout << "I am in " << specilization << endl;
    }

    Engineer(){
        cout << "Constructor of Engineer" << endl;
    }
};

class Youtuber{
    public:
    int subscribers;

    void contentcreator(){
        cout << "I have " << subscribers << endl;
    }
    Youtuber(){
        cout << "Constructor of Youtuber" << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber{
    public:
    string name;

    CodeTeacher(string name, string specilization, int subscribers){
        this->name = name;
        this->specilization = specilization;
        this->subscribers = subscribers;
    }

    CodeTeacher(){
        cout << "Constructor of CodeTeacher" << endl;
    }

    void show(){
        cout << name << endl;
        work();
        contentcreator();
    }
};

int main(){
    // CodeTeacher A1("Manu", "CSE", 234543);
    CodeTeacher A1;
    A1.show();
    return 0;
}