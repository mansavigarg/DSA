#include<iostream>
using namespace std;

void convertToUpperCase(char ch[], int size){
    int index = 0;

    while(ch[index] != '\0'){
        char currentCharacter = ch[index];
        // check if lower case then make it upper case
        if(currentCharacter >= 'a' && currentCharacter <= 'z' ){
            ch[index] = currentCharacter - 'a' + 'A';
        }
        index++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);

    convertToUpperCase(ch,100);
    cout << ch << endl;

    return 0;
}