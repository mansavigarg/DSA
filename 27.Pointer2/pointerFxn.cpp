#include<iostream>
using namespace std;

void solve(int arr[], int size){
    cout << "Size of array inside the function: " << sizeof(arr) << endl;

    cout << "Inside solve main -> arr: " << arr << endl;
    cout << "Inside solve main -> &arr: " << &arr << endl;


}
 
int main(){
    int arr[] = {1,2,3,4,5};
    cout << arr << endl;
    cout << "Size of array: " << sizeof(arr) << endl;
    cout << "Inside main -> arr: " << arr << endl;
    cout << "Inside main -> &arr: " << &arr << endl;

    solve(arr,5);
    return 0;
}