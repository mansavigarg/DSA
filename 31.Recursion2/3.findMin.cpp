#include <iostream>
#include <climits>
using namespace std;

void findMin(int arr[], int size, int index, int &mini)
{
    // base case
    if (index >= size)
    {
        return;
    }

    // processing
    mini = min(mini, arr[index]);

    // recursive call
    findMin(arr, size, index + 1, mini);
}

int main()
{

    int arr[] = {11, 20, 31, 40, 51};
    int size = 5;
    int index = 0;

    int mini = INT_MAX;
    findMin(arr, size, index, mini); 
    // ! yha pr mini ko by refrernce pass krna padega as hme isi mimi mein update krna hai
    // @ If we want to store ans in any variable (in this case it is mini) and we are passing this variable to another function to get the value, then we need to make sure to PASS IT BY REFERENCE so as to update the value in original variable.
    cout << "Minimum number in array: " << mini << endl;
    return 0;
    
}