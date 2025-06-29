#include<iostream>
using namespace std;
 

// //! This is pass by value 
// void solve(int* p){
//     p = p+1;
// }


//! This is pass by reference  
void solve(int* &p){
    p = p+1;
}

int main(){
    
    int a = 5;
    int * p = &a;

    cout << "p: " << p << endl;
    cout << "&p: " << &p << endl;
    cout << "*p: " << *p << endl;

    solve(p);

    cout << "p: " << p << endl;
    cout << "&p: " << &p << endl;
    cout << "*p: " << *p << endl;
    return 0;
}