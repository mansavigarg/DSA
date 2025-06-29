#include<iostream>
using namespace std;

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &v){
    int n = v.size();
    // leave loop for i = 0
    for(int i = 1; i<n; i++){
        int key = v[i];
        int j = i - 1;

        // move element of arr[0..i-1] that are greater than key to one position ahead of there current postion
        while( j>= 0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key; 

    }
     
}

int main(){
    vector<int> v = {2,57,33,88,6,58,-33,-5,0};
    insertionSort(v);
    print(v);
    
    return 0;
}