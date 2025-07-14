#include<iostream>
using namespace std;

class Info{
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int val, int row, int col){
            this->data = val;
            this->rowIndex = row;
            this->colIndex = col;
        }
};

class compare{
    public:
        bool operator()(Info* a, Info* b){
            return a->data > b->data; // thhis generates min heap
        }
};
// class compare{
//     public:
//         bool operator()(Info* a, Info* b){
//             return a->data < b->data; // thhis generates max heap
//         }
// };

void mergeKSortedArray(int arr[][4], int n, int k, vector<int> &ans){

    priority_queue<Info*, vector<Info*>, compare> pq;

    // Step 1: process first k elements
    for(int row = 0; row < k; row++){
        int element = arr[row][0];
        Info* temp = new Info(element, row, 0);
        pq.push(temp);
    }

    // Step 2: pop and push remaing elements in the the heap
    while(!pq.empty()){
        Info* temp = pq.top();
        pq.pop();

        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        // store in ans vector
        ans.push_back(topData);

        //  jis row se aabi pop kiya hai uska next element insert krna hai heap mein
        if(topCol + 1 < n ){
            // iska mltb aabi row mein element bache hue hai 
            Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1);
            pq.push(newInfo);
        }
    }
}

int main(){
    int arr[3][4] = {
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };
    int n = 4;
    int k = 3;

    vector<int> ans;
    mergeKSortedArray(arr, n, k, ans);
    cout << "Printing Array: " << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}