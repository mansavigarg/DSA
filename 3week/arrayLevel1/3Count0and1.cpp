#include<iostream>
using namespace std;

void countZeroOne(int arr[], int size){
    int zeroCount = 0;
    int oneCount = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == 1){
            oneCount++;
        }
        if(arr[i] == 0){
            zeroCount++;
        }
    }
    cout << "Zero " << zeroCount << endl;    
    cout << "one " << oneCount << endl;    
}

int main(){
    int arr[] = {1,0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0};

    int size = 18;
    countZeroOne(arr, size);

    return 0;
}