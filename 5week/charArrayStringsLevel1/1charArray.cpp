#include<iostream>
using namespace std;

int main(){
    // creation
    char ch[100];

    // ! input
    // cin >> ch;
    // ! full line input
    cin.getline(ch, 100);

    // printing
    cout << ch << endl;

    // printing each character
        // for(int i = 0; i < 10; i++){
        //     cout << "At index: " << i << " " << ch[i] << endl;
        // }
    
        // char temp = ch[6];
        // int value = (int)temp;
        // cout << value << endl;
    return 0;
}