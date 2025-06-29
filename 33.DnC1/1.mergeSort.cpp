#include<iostream>
using namespace std;

void merge(int arr[], int start, int end){

    int mid = start + (end-start)/2;  

    // finding length of left and right array
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    //creating empty left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from the original array to left array
    int k = start ; // k -> starting index of left array values in original array
    for(int i = 0; i < lenLeft; i++){
        left[i] = arr[k];
        k++;
    }
    // copy values from the original array to right array
    k = mid+1 ; // k -> starting index of left array values in original array
    for(int i = 0; i < lenRight; i++){
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    // left and right array is already sorted 
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start; // yhi pr galti kroge

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {

        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;        
        }
    }

    // 2 more cases
    //@ 1 case -> left array exhaust ho gaya hai but right array me elements abhi bhi bache hai
    while (rightIndex < lenRight ){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++; 
    }

    //@ 2 case -> right array exhaust ho gaya hai but left array me elements abhi bhi bache hai
    while (leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    
    // 1 more step remaining - good practice
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end){
    // base case
    if(start>=end){
        //invalid array & single element
        return;
    }

    // Break
    int mid = start + (end-start)/2;
    //* Left array: start -> mid
    //* Right array: mid+1 -> end

    //! call Recursion bhaiya 
    //! and sort the left and right array

    // recursive call for left array
    mergeSort(arr,start,mid);
    // recursive call for right array
    mergeSort(arr,mid+1,end);

    // merge two sorted array
    merge(arr,start,end);
}


int main(){
    int arr[] = {2,1,2,6,5,4};
    int size = 6;
    int start = 0;
    int  end = size - 1;

    cout << "Before merge sort: " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr,start,end);

    cout << "After merge sort: " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}