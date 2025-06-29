#include<iostream>
using namespace std;

int main(){
    int a = 5;
    cout << "a || Value of a is : " << a << endl;
    cout << "&a || Address of a is : " << &a << endl;

    // pointer creation
    int* ptr = &a;

    //accessing value stored at address stored in ptr
    cout << "*ptr || Accessing value: " << *ptr << endl;

    // printing the value of ptr which is the address of the value stored
    cout << "ptr || Value of ptr is: " << ptr << endl;

    // address of ptr 
    cout << "&ptr || Address ptr is: " << &ptr << endl;
 
    cout << "SIZZZE is: " << sizeof(a) << endl;
    cout << "SIZZZE is: " << sizeof(ptr) << endl;

    return 0;
}
