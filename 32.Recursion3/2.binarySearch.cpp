#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target){

    int mid = start + (end-start)/2;

    if(start>end){
        // element not found
        return -1;
    }

    // 1 case khud dekh lo
    if(arr[mid] == target){
        return mid;
    }
    // baki recursion
    if(arr[mid] < target){
        return binarySearch(arr,mid+1,end,target);
    }
    else return binarySearch(arr,start,mid-1,target);

}


int main(){
    int arr[] = {11,22,33,44,55,66,77,88,99};
    int size = 9;
    int start = 0;
    int end = 8;
    int target = 66;

    cout << binarySearch(arr,start,end,target) << endl;
    return 0;
}