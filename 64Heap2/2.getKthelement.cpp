#include<iostream>
using namespace std;

int getKthSmallestElement(int arr[],int n, int k){
    priority_queue<int> pq;

    // first k element ko process krna hai heap mein
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    // remaning element ko tbi insert krnege jab vo root se chote honge
    for(int i = k; i < n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}


int getKthLargestElement(int arr[],int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // first k elements ko heap mein daal do
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    // remaining elements ko tbi insert krnege jab vo root se bade honge
    for(int i = k; i < n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main(){
    int arr[] = {3,5,4,6,9,8,7};
    int n = 7;
    int k = 3;
    cout << getKthSmallestElement(arr, n, k) << endl;
    cout << getKthLargestElement(arr, n, k) << endl;
    return 0;
}