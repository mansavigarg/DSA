#include<iostream>
using namespace std;

class Customer{
    string name;
    int *data;

    public:
    Customer(){
        name = "4";
        cout << name << " Constructor is called" << endl;
    }
    Customer(string name){
        this->name = name;

        cout << name ;
        cout << " Constructor is called" << endl;
    }

    //$ destructor 
    ~Customer(){
        cout << name << " Destructor is called" << endl;
    }

};


int main(){
    Customer A1("1"),A2("2"),A3("3");
    Customer *A4 = new Customer; // here memory will not be deletd by its own so need to delete manually
    delete A4;

    return 0;
}