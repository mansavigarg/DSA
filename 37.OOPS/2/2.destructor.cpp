#include<iostream>
using namespace std;

class Customer{
    string name;
    int *data;

    public:
    Customer(){
        name = "Manu";
        data = new int;
        *data = 199;
        cout << "Constructor is called" << endl;
    }

    //$ destructor 
    ~Customer(){
        delete data;
        cout << "Destructor is called" << endl;
    }
};


int main(){
    Customer A1;
    return 0;
}