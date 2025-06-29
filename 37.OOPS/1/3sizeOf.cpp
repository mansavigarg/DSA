#include<iostream>
using namespace std;

class a{

    // //$ it will take 12bytes
    // char a;
    // int b; 
    // char c;

    //$ it will take 8bytes
    char a;
    char c;
    int b; 
};

int main(){
    
    a obj;
    cout << sizeof(obj) << endl;
    return 0;
}