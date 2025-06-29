#include<iostream>
using namespace std;

class Complex{
    int real, img;
    public:
    Complex(){
        // default constructor
    }
    Complex(int real,int img){
        this->real = real;
        this->img = img;
    }
    void display(){
        cout << real << " + i" << img << endl;
    }

    //@ operator overloading

    Complex operator+(Complex &C){
        Complex ans;
        ans.real = real + C.real;
        ans.img = img + C.img;
        return ans;
    }
};

int main(){
    Complex C1(3,2);
    Complex C2(5,4);
    Complex C3 = C1 + C2;
    C3.display();
    
    return 0;
}