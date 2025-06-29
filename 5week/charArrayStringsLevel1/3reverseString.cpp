#include<iostream>
using namespace std;

void reverseString(char ch[], int size){
    int i = 0;
    int j = size - 1;
    while(i<j){
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}



int main(){
    char ch[100];

    cin.getline(ch,100);


    cout << "Before: " << ch << endl;
    int len = strlen(ch);
    // reverseString(ch,len);
    reverse(ch, ch+len);
    cout << "After: " << ch << endl;
    return 0;
}