#include<iostream>
using namespace std;


bool checkSorted(int arr[], int size, int index){
    // base case
    if(index >= size){
        return true;
    }
    if(arr[index] > arr[index-1]){
        return checkSorted(arr,size,index+1);
    }
    else return false;
}


int main(){

    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 1;

    bool isSorted = checkSorted(arr,size,index);

    if(isSorted){
        cout << "Array is sorted." << endl;
    }
    else cout << "Array is not sorted." << endl;
 
    return 0;
}