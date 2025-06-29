#include<iostream>
using namespace std;

class Customer
{
    string name;
    int acc_num, balance;
    
    public:

    //$ default constructor
    Customer(){
        // putting values by default
        name = "Manu";
        acc_num = 123;
        balance = 12345;
        cout << "Cunstractor is called" << endl;
    }

    //$ parametrized constructor
    Customer(string name, int acc_num, int balance){
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
    }

    //$ constructor overloading
    Customer(string a, int b){
        name = a;
        acc_num = b;
        balance = 50; // putting default value for balance
    }

    // //$ Inline constructor
    // inline Customer(string a, int b, int c): name(a), acc_num(b), balance(c){

    // }

    //$ Copy constructor
    Customer(Customer &B){
        name = B.name;
        acc_num = B.acc_num;
        balance = B.balance;
    }



    void display(){
        cout << name << " ";
        cout << acc_num << " ";
        cout << balance << endl;
    }
};

int main(){

    Customer A1;
    Customer A2("Shivani",89,8849);
    Customer A3("Shivam",45);
    A1.display();
    A2.display();
    A3.display();

    Customer A4(A3);
    A4.display();

    // another way to aasign values
    Customer A5;
    A5 = A3;
    A5.display();
    
    return 0;
}