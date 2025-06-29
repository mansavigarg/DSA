#include<iostream>
using namespace std;

int findLastOccurance(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end-start) / 2;
        if(target == arr[mid]){
            ans = mid;
            start = mid + 1;
        }
        else if(target > arr[mid]){
            start = mid + 1;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
    }
    return ans;
    
}

int main(){
    int arr[] = {10,20,30,30,30,30,30,40,50};
    int n = 8;
    int target = 30;

    int ansIndex = findLastOccurance(arr,n,target);
    cout << "Element found at index: " << ansIndex << endl;
    return 0;
}