#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;

    while(start<=end){
        // ! Integer Overflow:
        // The expression int mid = (start + end) / 2 can potentially lead to integer overflow if start and end are large. A safer approach is:
        int mid = start + (end - start) / 2;

        // found
        if(arr[mid] == target){
            // returning index of found element
            return mid;
        }

        else if(target > arr[mid]){
            // right mein jao
            start = mid + 1;
        }

        else if(target < arr[mid]){
            // left mein jao
            end = mid - 1;
        }
    }

    // if element not found then we have to return a invalid index
    return -1;
}

int main(){
    int arr[] = {1,3,5,6};
    int target = 5;
    int n = 4;

    int ansIndex = binarySearch(arr,n,target);

    if (ansIndex == -1){
        cout << "Element not found" << endl;
    }else cout << "Element found at index: " << ansIndex << endl;
    return 0;
}