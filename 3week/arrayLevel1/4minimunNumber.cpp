#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int arr[] = {3,7,44,7,88,0,51,-66};
    int size = 8;
    int minAns = INT_MAX;

    for (int i = 0; i < size; i++){
        if (arr[i] < minAns){
            minAns = arr[i];
        }
    }
    cout << "minans is " << minAns << endl ;
    return 0;
}