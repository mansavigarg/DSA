#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &v){
    int n = v.size();

    for (int i = 0; i < n-1; i++){
        int didSwap = 0;
        for (int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
        }
    }
}

int main(){
    vector<int>v = {4, 5, 3 ,3,66,7,-765, 2 , 1};
    bubbleSort(v);
    print(v);
    return 0;
}