#include<iostream>
using namespace std;

class Human{
    private:
    int a;
    protected:
    int b;
    public:
    int c;

    void fun(){
        a = 1;
        b = 2;
        c = 3;
    }

};

int main(){

    Human Mansavi;
    Mansavi.c = 10;
    Mansavi.fun();

    return 0;
}