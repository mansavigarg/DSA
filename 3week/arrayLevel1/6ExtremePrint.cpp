#include<iostream>
using namespace std;

void extremePrintArray(int arr[], int size){
    int left = 0;
    int right = size-1;

    while(left <= right){
        if (left == right){
            cout << arr[left];
        } 
        else {
        cout << arr[left] << " " << arr[right] << " " ;            
        }
        left++;
        right--;
    }
}

int main(){
    int arr[] = {15,25,35,45,55,65,75};
    int size = 7;

    extremePrintArray(arr,size);
    return 0;
}