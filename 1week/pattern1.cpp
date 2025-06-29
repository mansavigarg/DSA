#include<iostream>
using namespace std;

int main(){
    int n , m;
    cout << "Enter no of rows " ;
    cin >> n;
    cout << "Enter no of cols " ;
    cin >> m;
    for( int i = 0; i < n; i++){
        for (int j = 0 ; j < n-i ; j++){
            cout << j + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}

// #include<iostream>
// using namespace std;

// int main(){
//     int n ;

//     if(cin>>n){
//         cout << "mansavi";
//     }
//     return 0;
// }