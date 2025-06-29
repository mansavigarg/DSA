#include<iostream>
using namespace std;

int main(){
    vector<int> arr = { 5,6,8,9,6,5,5,6};
    int n = 8;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    return 0;
}


vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> ans;
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int floor = -1;
        int ceil = -1;
        
        sort(arr.begin(), arr.end());
        
        while(start <= end){
            int mid = start + (end-start) / 2;
            
            if(x < arr[0]){
                break;
            }
            
            if(x == arr[mid]){
                floor = arr[mid];
                break;
            }
            if(arr[mid] < x){
                floor = arr[mid];
                start = mid + 1;
            }
            else if (arr[mid] > x){
                end = mid - 1;
            }
        }
        
        
        while(start <= end){
            int mid = start + (end-start) / 2;
            
            if(x>arr[n-1]){
                break;
            }
            
            if(x == arr[mid]){
                ceil = arr[mid];
                break;
            }
            if(arr[mid] < x){
                start = mid + 1;
            }
            else if (arr[mid] > x){
                ceil = arr[mid];
                end = mid - 1;
            }
        }
        
        
        
        
        ans.push_back(floor);
        ans.push_back(ceil);
        return ans;
    }