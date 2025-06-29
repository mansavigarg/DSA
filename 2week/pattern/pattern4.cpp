#include<iostream>
using namespace std;

int main(){
    int n , m;
    cout << "Enter no of rows " ;
    cin >> n;
    cout << "Enter no of cols " ;
    cin >> m;

    // Hollow half Pyramid
    for (int i = 0; i < n; i++){
        char ch;
        for (int j = 0; j< i+1; j++){
            ch = j + 1 +'A'-1;
            cout << ch ;
        }

        // jb tk A tk ni paumchoge tb tk print kro
        for (char alph = ch; alph > 'A' ; ){
            alph--;
            cout << alph;
        }

        cout << endl;
    }

    cout << endl;
    // second method
    cout << "This is second method" << endl;
    for (int i = 0; i < n; i++) {
        // Print increasing part of the pattern
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j);
        }

        // Print decreasing part of the pattern
        for (int j = i - 1; j >= 0; j--) {
            cout << char('A' + j);
        }

        cout << endl;
    }
    
    
    return 0;
}



