#include<iostream>
#include <algorithm>
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

int totalOccurance(int arr[], int n, int target){
    int firstOcc = findFirstOccurance(arr,n,target);
    int lastOcc = findLastOccurance(arr,n,target);
    int total = lastOcc - firstOcc + 1;
    return total;
}


int main(){
    int arr[] = {10,20,30,30,30,30,30,40,50};
    int n = 8;
    int target = 30;

    int ans = totalOccurance(arr,n,target);
    
    cout << "Total occurance is: " << ans << endl;

    return 0;
}




// ! another way to find the total occurance of an element is:
// * we also need to include a file in header -> #include<algorithm> 

int countOccurrences(int arr[], int n, int target) {
    // Get pointer to the first occurrence of target
    int* first = lower_bound(arr, arr + n, target);
    
    // Get pointer to the position just after the last occurrence
    int* last = upper_bound(arr, arr + n, target);

    // Check if the element exists in the array
    if (first == (arr + n) || *first != target) {
        return 0; // Target not found
    }

    // Count of occurrences = (last - first)
    return (last - first);
}