#include<iostream>
using namespace std;

void printFirstNegative(int *arr, int n, int k){

    deque<int> dq;

    //# PROCESS FIRST K ELEMENTS - first window
    for(int index = 0; index < k; index++){
        int element = arr[index];
        if(element < 0){
            dq.push_back(index);
        }
    }

    //# Process remaining windows -> removal and addition
    for(int index = k; index < n; index++){
        // aage badhne se phele purani window ka ans nikal do
            if(dq.empty()){
                cout << "0 ";
            }else{
                cout << arr[dq.front()] << " ";
            }
        // Removal -> jo bi index out of range hai usko queue mein se remove kr do
            if(!dq.empty() && index - dq.front() >= k){
                // out of range wala element hai
                dq.pop_front();
            }
        // Addition
            if(arr[index] < 0){
                dq.push_back(index);
            }
    }

    // last wali window ka ans print kr do
    if(dq.empty()){
        cout << "0 " << endl;
    }else{
        cout << arr[dq.front()] << " ";
    }
}

int main(){

    queue<int> q;

    int arr[] = {2,-5,4,-1,-2,0,5};
    int size = 7;
    int k = 3;

    printFirstNegative(arr,size,k);

    //  cout << "Printing queue: ";
    //  while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    //  }
    //  cout << endl;
    return 0;
}