#include<iostream>
using namespace std;

int findLenth(char ch[], int size){
    int length = 0;

    for(int i = 0; i < size; i++){
        if(ch[i] == '\0'){
            // ruk jao
            break;
        }
        else {length++;}
    }
    return length;
}

// !using while loop
// int findLenth(char ch[], int size){
//     int index = 0;

//     while(ch[index] != '\0'){
//         index++;
//     }
//     return index;
// }

int main(){
    char ch[100];
    cin >> ch;

    int len = findLenth(ch, 100);

    cout << "Length of string is: " << len << endl;

    // length using STL fxn
    cout << "Length of string is: " << strlen(ch) << endl;

    return 0;
}