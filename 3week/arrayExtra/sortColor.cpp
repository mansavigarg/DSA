#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,1,0,2,1,0,0,2,2,1,1,0};
    int size = 12;
    int red = 0;
    int white = 0;
    int blue = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == 0) {
            red++;
        }
        if(arr[i] == 1){
            white++;
        }
        if(arr[i] == 2){
            blue++;
        }
    }
    vector<int>brr;
    for(int i = 0; i < red;i++ ){
        brr.push_back(0);
    }
    for(int i = 0; i < red;i++ ){
        brr.push_back(1);
    }
    for(int i = 0; i < red;i++ ){
        brr.push_back(2);
    }
    for (int i = 0; i < size ; i++){
        cout << brr[i] << " ";
    }
    return 0;
}



