#include<iostream>
using namespace std;

class Customer{
    string name;
    int balance, acc_num;

    public:
    Customer(string name, int balance, int acc_num){
        this->name = name;
        this->balance = balance;
        this->acc_num = acc_num;
    }

    //depost
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            cout << amount << " is credited successfully" << endl;
        }
    }

    //withdraw

    void withdraw(int amount){
        if(amount>0&&amount<=balance){
            balance-=amount;
            cout << amount << " is debited successfully" << endl;
        }
    }
};
int main(){

    Customer C1("MAnu" , 1000, 17);
    C1.deposit(100);
    C1.withdraw(6000);

return 0;
}