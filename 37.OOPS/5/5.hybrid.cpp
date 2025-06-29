#include<iostream>
using namespace std;

//student
//boy
//girl
//male
//female

class Student{
    public:
    void print(){
        cout << "i am a student." << endl;
    }
};
class Male {
    public:
    void malePrint(){
        cout << "I am male" << endl;
    }
};
class Female {
    public:
    void FemalePrint(){
        cout << "I am Female" << endl;
    }
};

class Girl: public Student, public Female{
    public:
    void GirlPrint(){
        cout << "I am a Girl" << endl;
    }
};
class Boy: public Student, public Male{
    public:
    void BoyPrint(){
        cout << "I am a Boy" << endl;
    }
};



int main(){

    Girl G1;
    G1.GirlPrint();
    G1.print();

    Boy B1;
    B1.BoyPrint();
    B1.print();
    
    return 0;
}