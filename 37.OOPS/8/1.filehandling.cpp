#include<iostream>
#include<fstream>
using namespace std;

int main(){

    // file ko open krna 
    ofstream fout;
    fout.open("zoom.txt"); // file ko open kr dena and if file present ni hai then create the file and then open it

    // write kr skata hu 
    fout << "Hello manu";

    fout.close(); // file handling k resources ko relase krva pau

    
    return 0;
}