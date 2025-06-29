#include<iostream>
using namespace std;

int main(){
    int arr[] = {23,0,-7,12,-10,-11,40,60};
    int size = 7;
    int j = 0;
    for(int index = 0;index<size;index++){
        if (arr[index] < 0){
            swap(arr[index],arr[j]);
            j++;
        }
    }

    for( int i = 0; i< size ; i++){
         cout << arr[i] << " ";
    }
    return 0;
}   