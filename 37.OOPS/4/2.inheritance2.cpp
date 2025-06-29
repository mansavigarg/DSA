#include<iostream>
using namespace std;

class Human{

    public:
    string name;
    int age, weight;
};

class Student: protected Human{

    private:
    int roll_num, fees;

    public:
    void fun(string n, int a, int w){
        name = n;
        age = a; 
        weight = w;
    }
};

int main(){

    Student A;
    // A.name = "Manu";

    A.fun("masn",213,324);
    
    return 0;
}