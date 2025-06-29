#include<iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int left = 0;
    int right = size-1;

    while(left <= right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }


    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {15,25,35,45,55,65,75};
    int size = 7;

    reverseArray(arr,size);
    return 0;
}