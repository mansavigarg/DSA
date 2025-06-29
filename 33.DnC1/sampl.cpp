#include<iostream>
using namespace std;


void merge(int arr[], int start, int end){
    int mid = start + (end-start) / 2;

    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    int *leftarr = new int[lenLeft];
    int *rightarr = new int[lenRight];

    int k = start;
    for(int i = 0 ; i <= lenLeft; i++){
        leftarr[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int j = 0; j <= lenRight; j++){
        rightarr[j] = arr[k];
        k++;
    }


    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while (leftIndex < lenLeft && rightIndex < lenRight){
        if (leftarr[leftIndex] < rightarr[rightIndex]){
            arr[mainArrayIndex] = leftarr[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }else{
            arr[mainArrayIndex] = rightarr[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    while (rightIndex < lenRight ){
        arr[mainArrayIndex] = rightarr[rightIndex];
        mainArrayIndex++;
        rightIndex++; 
    }

        while (leftIndex < lenLeft){
        arr[mainArrayIndex] = leftarr[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }


        delete[] leftarr;
    delete[] rightarr;
}

void mergeSort(int arr[], int start, int end){
    int mid = start + (end-start)/2;

    // base case
    if(start>=end){
        return ;
    }

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    merge(arr,start,end);

}

int main(){
    int arr[] = {5,4,7,6,2,1};
    int size = 6;
    int start = 0;
    int end = size-1;

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
}