#include<iostream>
using namespace std;

int getUnique(int arr[],int size){
    int ans = 0;
    for (int i = 0; i < size; i++){
        ans = ans^arr[i];
    }
    return ans;

}
int main(){
    int arr[] = {2,10,2,12,11,12,11,9,10};
    int size = 9;

    int finalAns = getUnique(arr,size);
    cout << finalAns << endl;
    return 0;
}