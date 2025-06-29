
/**
 * ! int n;
 * ! cin >> n;
 * ! int *arr = new int[n];
*/ 


// ! Here even though it is a dynamic memory allocation but still we are taking input from the user and in future if we want to insert more elements than the inputed value, then we will not be able to insert or push the elememts in the array

// so we introduce the vector here
// vector array hi hai

#include<iostream>
#include <vector>
using namespace std;

void print(vector<int>v){
    //to find the current size of the vector
    int size = v.size();
    for(int i = 0; i < size; i++){
        // one way to print
        // * cout << v[i] << " ";
        // other way to print
        cout << v.at(i) << " "; 
    }
    cout << endl;
}

// ! vector native method to print 
void print2(vector<int>v){
    for(auto it:v){
        cout << it << " ";
    }
    cout << endl;
}
int main(){

    // vector initialization
    vector<int>arr; // ! default with no data, 0 size
    vector<int>arr2( 5, -1); // ! init (starting size given but still dynamic) with specific size of n (here 5) and specific data (here -1)
    vector<int>arr3 = {1,2,3,4,5,6}; // ! initilization with specific values
    vector<int>arr4{1,2,3,4,5,6}; // ! same as above

    // ! how to copy vector 
    vector<int>arr5 = {1,2,3,4,5};
    vector<int>arr6(arr5); // copy values of arr5 to arr6

    // declaring a vector which is of int type and name is v
    vector<int>v;

    // inserting values
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    print2(v);

    // pop -> delete -> END
    v.pop_back();
    print(v);

    v.pop_back();
    print(v);

    v.pop_back();
    print(v);
    
    v.pop_back();
    print(v);

    //inserting values in a loop
    cout << "Enter the values to insert: " ;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    print(v);

    // Even though we took input from user to add values but still we can add more in vector
    for(int i = 0; i < 40; i++){
        v.push_back(2310);
    }
    print(v);

    return 0;
}