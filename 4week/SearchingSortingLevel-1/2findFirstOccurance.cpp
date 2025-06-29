#include<iostream>
using namespace std;

int findFirstOccurance(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int ans = -1; //initilize with -1 so that if element not found then return -1

    while(start<=end){
        int mid = start + (end-start) / 2;

        if(arr[mid] == target){
            // Step 1: store the index is ans 
            ans = mid ;
            // Step 2: left me jao
            end = mid - 1;
        } 
        else if(target > arr[mid]){
            // right me jao
            start = mid + 1;
        }

        else if(target < arr[mid]){
            // left mein jao
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {10,30,30,30,30,30,40,50};
    int n = 8;
    int target = 30;


    int ans = findFirstOccurance(arr,n,target);
    cout << "First Occurance is at: " << ans << endl;
    return 0;
}