#include<iostream>
using namespace std;

int searchNearlySortedArray(int arr[],int n, int target){
    int s = 0;
    int e = n-1;
    
    while( s <= e){
        int mid = s + (e-s) / 2;

        if(mid-1 >= 0 && arr[mid-1] == target){
            return mid - 1;
        }
        if(arr[mid] == target){
            return mid;
        }
        if(mid+1 < n && arr[mid+1] == target){
            return mid + 1;
        }
        if(target < arr[mid]){
            e = mid - 2;
        }
        else if(target > arr[mid]){
            s = mid + 2;
        }
    }
    return -1;
}

int main(){
    int arr[] = {20,10,30,50,40,70,60};
    int n = 7;
    int target = 20;

    cout << searchNearlySortedArray(arr, n, target) << endl;

    return 0;
}