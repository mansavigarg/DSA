#include<iostream>
using namespace std;

void fun(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;

    int *arr = new int[n];

    fun(arr,n);
    return 0;
}

 
// ! Here even though it is a dynamic memory allocation but still we are taking input from the user and in future if we want to insert more elements than the inputed value, then we will not be able to insert or push the elememts in the array