#include<iostream>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int capacity;
    int size;

    MaxHeap(int capacity){
        this->arr = new int[capacity];
        this->capacity = capacity;
        // size = current number of elements in heap
        this->size = 0;
    }
    void insert(int val){
        if(size == capacity){
            cout << "Heap OverFlow" << endl;
            return;
        }
        // size increase kar jayega
        size++;
        int index = size;
        arr[index] = val;

        // take the value to its correct postion
        while(index > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }
    void printHeap(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int deleteFromHeap(){
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // last element ko dlt kr do uski original postion se
        size--;

        int index = 1;
        // Heapify
        while(index < size){
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;

            // find out krna hai , sbse bada kon hai 
            int largestIndex = index;
            // check left child
            if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                largestIndex = leftIndex;
            }
            if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                largestIndex = rightIndex;
            }

            // no change means element aapni shi jaghe pr hai
            if(index == largestIndex){
                break;
            }else{
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
    }
};

void heapify(int *arr, int n, int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;
    int largestKaIndex = index;

    // tino mein se max niklana hai ki kon sa hai
    if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
        largestKaIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
        largestKaIndex = rightIndex;
    }

    // after the above 2 conditions, largestkaIndex will be pointing towards the largest element among the 3
    if(index != largestKaIndex){
        swap(arr[index], arr[largestKaIndex]);
        // aab recursion sambhal lega
        index = largestKaIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n){
    for(int index = n/2; index > 0; index--){
        heapify(arr, n , index);
    }

}
int main(){
    MaxHeap h(20);
    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing Heap: " << endl;
    h.printHeap();
    
    int ans = h.deleteFromHeap();
    cout << "Ans: " << ans << endl;
    
    cout << "Printing Heap: " << endl;
    h.printHeap();

    return 0;
}