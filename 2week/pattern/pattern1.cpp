#include<iostream>
using namespace std;

int main(){
    int n , m;
    cout << "Enter no of rows " ;
    cin >> n;
    cout << "Enter no of cols " ;
    cin >> m;
    
    // Full pyramid
    for (int i = 0; i < n; i++){
        for (int j= 0; j < n-i-1 ; j++){
            cout << " " ;
        }
        for (int k= 0; k < i+1 ; k++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;


    // Half pyramid
    for (int i = 0; i < n; i++){
        for (int j= 0; j < n-i-1 ; j++){
            cout << " " ;
        }
        for (int k= 0; k < i+1 ; k++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    
    // Inverted Full pyramid
    for (int i = 0; i < n; i++){
        //spaces
        for (int j= 0; j < i ; j++){
            cout << " " ;
        }
        for (int k= 0; k < n-i ; k++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;


    // Inverted half pyramid
    for (int i = 0; i < n; i++){
        //spaces
        for (int j= 0; j < i ; j++){
            cout << " " ;
        }
        for (int k= 0; k < n-i ; k++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;



    // Diamond 
    int num = n/2;
    for (int i = 0; i < num; i++){
        for (int j= 0; j < num-i-1 ; j++){
            cout << " " ;
        }
        for (int k= 0; k < i+1 ; k++){
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < num; i++){
        for (int j= 0; j < i ; j++){
            cout << " " ;
        }
        for (int k= 0; k < num-i ; k++){
            cout << "* ";
        }
        cout << endl;
    }

    // Hollow half Pyramid
    for (int i = 0; i < n; i++){
        //spaces
        for (int j= 0; j < n-i ; j++){
            if (i== 0 || i == n-1){
            cout << "* " ;
            }else{
                if(j==0 or j == n -i-1 ){
                    cout << "* ";
                }else cout << "  ";
            }
        }
        cout << endl;
    }





    return 0;
}