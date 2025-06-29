#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ifstream fin;

    // file ko open krna 
    fin.open("zoom.txt"); 

    // file ko read kro 
    char c;
    c = fin.get();
    while (!fin.eof())
    {
        cout << c;
        c = fin.get();
    }
    
    fin.close(); // file handling k resources ko relase krva pau

    return 0;
}