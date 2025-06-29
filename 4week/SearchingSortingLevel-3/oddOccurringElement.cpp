#include<iostream>
using namespace std;

int findOddOccurringElement(int arr[], int n){
    int s = 0; 
    int e = n-1;

    while (s <= e){
        int mid = s + (e-s) / 2;
        // single element
        if (s==e){
            return s;
        }

        // mid check -> even or odd
        if(mid & 1){ // mid-1 -> true -> odd number
            if(mid-1 >= 0 &&arr[mid-1] == arr[mid]){
                //rigth mein jao
                s = mid + 1;
            }
            else {
                // left mein jao
                e = mid - 1;
            }
        }
        else{
            //even
            if( mid+1 < n && arr[mid] == arr[mid+1]){
                //right mein jao
                s = mid + 2;
            }
            else {
                // ya to mein right part pr khada hu
                // ya to mein ans pr khada hu
                e = mid;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,10,2,2,3,3,2,5,5,6,6,7,7};
    int n = 13;

    int ans = findOddOccurringElement(arr,n);

    cout << arr[ans] << endl;
    return 0;
}