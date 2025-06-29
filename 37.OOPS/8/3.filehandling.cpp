#include<iostream>
#include<fstream>
using namespace std;

int main(){

    vector<int> arr(5);
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }

    //file open kro
    ofstream fout;
    fout.open("zero.txt");

    for(int i=0; i<5; i++){
        fout << arr[i];
    }

    fout.close();
    
    return 0;
}