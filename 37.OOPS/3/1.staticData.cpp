#include<iostream>
using namespace std;

class Customer{
    string name;
    int acc_num, balance;

    static int total_customer;
    static int total_balance;

    public:

    Customer(string name, int acc_num, int balance){
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_customer++;
        total_balance += balance;
    }

    // $ Static memory function
    // to access the static value of private throught a function directly
    static void accessStatic(){
        cout << "Total number of customer: " << total_customer << endl;
        cout << "Total balance: " <<  total_balance << endl;
    }

    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            total_balance+=amount;
        }
    }
    void withdraw(int amount){
        if(amount <= balance && amount > 0){
            balance -= amount;
            total_balance-=amount;
        }
    }

    void display(){
        cout << name << " " << acc_num << " " << balance << " " << total_customer << endl;
    }

    void display_customer(){
        cout << total_customer << endl;
    }
};

int Customer:: total_customer = 0;
int Customer:: total_balance = 0;


int main(){

    Customer A1("Manu",1, 1999);
    Customer A2("Shivam",2, 2299);
    // A1.display();
    // A2.display();
    // A2.display_customer();
    Customer A3("Shivani",3, 2449);
    // A3.display();
    // A2.display_customer();

    // to get total_customer if it is in public
    // Customer::total_customer = 5;   

    Customer::accessStatic();
    

    // A2.display_customer();
    // A1.display_customer();

    A1.deposit(500);
    Customer::accessStatic();
    A1.withdraw(200);
    Customer::accessStatic();

    return 0;
}