#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,6,7,8,9};
    int size = 5;

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            for(int k = 0; k<size; k++){
                cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
            }
        }
    }
    return 0; 
}