#include<iostream>
using namespace std;

void solve(int arr[], int size, int index, vector<int> &ans){
    // base case
    if(index >= size){
        return;
    }

    // processing 
    if(arr[index]%2 == 0){
        ans.push_back(arr[index]);
    }

    // recursive call
    solve(arr,size,index+1,ans);

}
int main(){

	int arr[] = {11,20,31,40,51};
	int size = 5;
	int index = 0;
	vector<int> ans;
	solve(arr, size, index, ans);
    
    //# printing vector 
	for(int num: ans) {
		cout << num << endl;
	}
    
    return 0;
}