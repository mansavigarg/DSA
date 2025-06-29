#include<iostream>
using namespace std;

class Customer {
    string name;
    int balance;
    int age;

    public:
    Customer(string name, int balance, int age){
        this->name = name;
        this->balance = balance;
        this->age = age;
    }

    void deposit(int amount){
        if(amount > 0 ){
            balance += amount;
        }
        else cout << "Invalid amount." << endl;
    }

    void currentBalance(){
        cout << "Current balance is: " << balance << endl;
    }
};

int main(){
    Customer A1("Manu",2000,21);
    A1.deposit(500);
    A1.currentBalance();
    A1.deposit(-500);
    A1.currentBalance();
    return 0;
}