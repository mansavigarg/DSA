#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout << "Hu Hu" << endl;
    }

    // //$ Pure Virtual Function
    // virtual void speak() = 0;
};

class Dog: public Animal{
    public:
    void speak(){
        cout << "Bark" << endl;
    }
    void roti(){
        cout << "Hello" << endl;
    }
};
class Cat: public Animal{
    public:
    void speak(){
        cout << "Meow" << endl;
    }
};

int main(){

    Animal *p;
    p = new Dog();
    p->speak();

    cout<<endl;
    // p->roti(); // this is not accessible as it is not same present in main Animal class as p os pointing to main Animal class only 

    Animal *r;
    vector<Animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());

    for (int i = 0; i < animals.size(); i++){
        r = animals[i];
        r->speak();
    }
    
    return 0;
}