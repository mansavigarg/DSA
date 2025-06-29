#include<iostream>
using namespace std;

int main(){
    int n = 5; // ! original variable name
    cout << &n;

    // * k is a reference variable refering to n
    int &k = n; // ! nick name to n as k

    // * m is a reference variable refering to n
    int &m = n; // ! nick name to n as m

    cout << "n: " << n << endl; 
    cout << "k: " << k << endl; 
    cout << "m: " << m << endl; 
    return 0;
}