#include<iostream>
using namespace std;

void printArray(int arr[], int size, int index){
    // base case
    if(index >= size){
        return;
    }
    
    // processing
    cout << arr[index] << " ";

    // recursive call
    printArray(arr,size,index+1);

}

int main(){

    int arr[] = {11,20,31,40,51};
	int size = 5;
	int index = 0;

    printArray(arr,size, index);

    
    return 0;
}