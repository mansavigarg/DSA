#include<iostream>
using namespace std;

bool checkPalindrome(char ch[], int n) {
    // n -> length of string
    int i = 0;
    int j = n-1;
    while (i <= j){
        if(ch[i] == ch[j]){
            i++;
            j--;
        }
        else{
            // character are not maching
            return false;
        }
    }
    return true;
}

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

int main(){
    char ch[100];
    cin.getline(ch,100);


    int len = findLenth(ch,100);

    bool isPalindrome = checkPalindrome(ch,len);

    if(isPalindrome){
        cout << "Valid Palindrome" << endl;
    }else cout << "Not valid Palindrome" << endl;

    return 0;
}