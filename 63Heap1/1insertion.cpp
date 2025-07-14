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
        // size shows the current number of elements in heap
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

        // take the value to its correct postion ---> heapify up
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
    }
};


class MinHeap{
    public:
        int *arr;
        int size;
        int capacity;

        MinHeap(int capacity){
            this->arr = new int[capacity];
            this->capacity = capacity;
            this->size = 0;
        }

        void insert(int val){
            if(size == capacity){
                cout << "Heap OverFlow" << endl;
                return;
            }
            // size ko increase krke , element daal do
            size++;
            int index = size;
            arr[index] = val;

            // Heapify up
            while(index > 1){
                int parentIndex = index/2;
                if(arr[index] < arr[parentIndex]){
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
};

int main(){
    MaxHeap hmax(5);
    // insertion
    hmax.insert(10);
    hmax.insert(20);
    hmax.insert(5);
    hmax.insert(11);
    hmax.insert(6);
    hmax.insert(6);

    cout << "Printing Heap: " << endl;
    hmax.printHeap();
    cout << endl;


    MinHeap hmin(20);

    hmin.insert(10);
    hmin.insert(20);
    hmin.insert(5);
    hmin.insert(11);
    hmin.insert(6);

    cout << "Printing Min Heap: " << endl;
    hmin.printHeap();
    return 0;
}