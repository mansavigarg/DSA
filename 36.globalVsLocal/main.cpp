#include<iostream>
using namespace std;

int x = 2; //$ Global Variable

void fun() {
    int x = 60;
    cout << x << endl;
    ::x = 40;
    cout << ::x << endl;
}

int main(){
    
    ::x = 4; // global 
    int x = 20; // local to main() fun
    cout << x << endl;
    cout << ::x << endl; //# accessing global variable

    {
        int x = 50;
        {
            int x = 44;
            cout << x << endl;
        }
        cout << x << endl;
        cout << ::x << endl;
    }

    fun();

    return 0;
}