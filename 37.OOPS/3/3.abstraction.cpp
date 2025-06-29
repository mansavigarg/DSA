#include<iostream>
using namespace std;

class Customer{
    string name;
    int acc_num, balance, age;

    static int total_customer;
    static int total_balance;

    public:

    Customer(string name, int acc_num, int balance, int age){
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
    void updateage(int age){
        if(age>0&&age<100){
            this->age = age;
        }
        else cout << "Invalid age." << endl;
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

    Customer A1("Manu",1, 1999,20);
    Customer A2("Shivam",2, 2299,21);
    Customer A3("Shivani",3, 2449,19);

    A1.updateage(-21);
    A1.deposit(500); 
    A1.display();
    A1.withdraw(200);
    A1.display();

    return 0;
}