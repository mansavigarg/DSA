#include<iostream>
using namespace std;

//! using recursion
void printPermutationRec(string str, int index){
    // base case
    if(index >= str.length()){
        cout << str << " ";
        return;
    }

    for(int j = index; j < str.length(); j++){
        swap(str[index], str[j]);

        // Recursion call
        printPermutationRec(str, index+1);

    }
}

//!using backtracking
void printPermutation(string &str, int index){
    // base case
    if(index >= str.length()){
        cout << str << " ";
    }

    for(int j = index; j < str.length(); j++){
        swap(str[index], str[j]);

        // Recursion call
        printPermutation(str, index+1);

        // BackTraking
        swap(str[index], str[j]);

    }
}

int main(){
    string str = "abc";
    int index = 0;
    printPermutation(str, index); cout << endl;
    printPermutationRec(str, index);
    cout << endl;
    cout << str;
    cout << endl;
    return 0;
}