#include<iostream>
using namespace std;

int main(){
    int n , m;
    cout << "Enter no of rows " ;
    cin >> n;
    cout << "Enter no of cols " ;
    cin >> m;


    // Fliped Solid Diamond
    int num = n/2;

    for (int i = 0; i < num; i++){
        for (int j =0; j < num - i;j++){
            cout << "* ";
        }
        for (int k = 0; k < (2*i)+1 ; k++){
            cout << "  ";
        }
        for (int k=0 ; k < num-i; k++){
            cout << "* ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < num; i++){
        for (int j = 0; j < i + 1;j++){
            cout << "* ";
        }
        for (int k = 0; k < (2*num)-(2*i)-1 ; k++){
            cout << "  ";
        }
        for (int k=0 ; k < i+1; k++){
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;


    // Method 1
    cout << "This is Method 1" << endl ;
    for (int i = 0; i < n; i++){
        for (int k =0; k < 2*i + 1 ; k++){
            if (k%2 == 1){
                cout << "*";
            }else cout << i+1;
        }
        cout << endl;
    }
    // Method 2
    cout << "This is Method 2" << endl ;
    for ( int i = 0 ; i < n; i++){
        for (int j = 0; j< i+1; j++){
            if (j==i){
                cout << i+1;
            }else cout << i+1 << "*";
        }
        cout << endl;
    }

    return 0;
}