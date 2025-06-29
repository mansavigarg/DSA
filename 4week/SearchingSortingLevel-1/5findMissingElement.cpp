#include<iostream>
using namespace std;

int findMissingElement(int arr[], int n){
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while(start <= end){
        int mid = start + (end-start) / 2;
        
        int diff = arr[mid] - mid;

        // If the difference is 1, search the right half
        if(diff == 1){
            start = mid+1;
        }
        // If the difference is greater than 1, search the left half
        else if(diff!=1){
            ans = mid;
            end = mid - 1; 
        }
        
    }

    // ! handling the case of last element as code is not working there
    if(ans + 1 == 0){
        return n+1;
    }
    
    return ans+1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 9;

    int ans = findMissingElement(arr,n);
    
    cout << "Missing element is: " << ans << endl;
    
    return 0;
}


//! Another approch to handle the last case in the main code only !//

// #include <iostream>
// using namespace std;

// int findMissingElement(int arr[], int n) {
//     int start = 0;
//     int end = n - 1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         int diff = arr[mid] - mid;

//         // If the difference is 1, search the right half
//         if (diff == 1) {
//             start = mid + 1;
//         } 
//         // If the difference is greater than 1, search the left half
//         else {
//             end = mid - 1;
//         }
//     }

//     // Return the missing element (start + 1 is the correct position)
//     return start + 1;
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 9}; // Missing 8
//     int n = 8;

//     int ans = findMissingElement(arr, n);

//     cout << "Missing element is: " << ans << endl;

//     return 0;
// }
