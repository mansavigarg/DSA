// ! Linear Search

#include<iostream>
using namespace std;

// present -> true 
// absent -> false

bool linearSearch(int arr[], int size, int target){
    for (int i=0; i<size; i++){
        if(arr[i] == target){
            //found
            return true; 
        }
    }
    // not found here
    return false;
}


int main(){
    // ! This is Method One of Linear Search
        cout << "This is Method One of Linear Search" << endl;
        int arr[5] = {2,4,6,8,10};
        int target = 10;
        int size = 5;

        bool flag = 0;
        // 0 -> not found
        // 1 -> found

        for(int i = 0; i<size ; i++){
            if(arr[i] == target){
                //found
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            cout << "Target Found" << endl;
        } else cout << "Not Found" << endl;

    // ! This is Method 2 usind The function call method
    cout << "This is Method 2 usind The function call method" << endl;
        // int arr[5] = {2,4,6,8,10};
        // int target = 10;
        // int size = 5;

        bool ans = linearSearch(arr,size,target);
        if(ans==1){
            cout << "Target Found" << endl;
        }else cout << "Not found" << endl;


    return 0;
}