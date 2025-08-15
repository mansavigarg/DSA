#include<iostream>
using namespace std;

int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n){
    // Base case
    if(index >= n) return 0;
    // if(index == n-1){
    //     if(wt[index] <= capacity)
    //         return profit[index];
    //     else return 0;
    // }


    // inclusion / exclusion
    int include = 0;
    if(wt[index] <= capacity){
        include = profit[index] + solveUsingRecursion(capacity-wt[index], wt, profit, index+1, n);
    }
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index+1, n);
    int ans = max(include, exclude);
    return ans;
}

void printdpArray(vector<vector<int>> &dp){
    cout  << endl << endl << "Printing dp array" << endl;
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}


int solveUsingMemo(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp){
    // Base case
    if(index >= n) return 0;
    // if(index == n-1){
    //     if(wt[index] <= capacity)
    //         return profit[index];
    //     else return 0;
    // }

    // already exist wala case
    if(dp[capacity][index] != -1) return dp[capacity][index];


    // inclusion / exclusion
    int include = 0;
    if(wt[index] <= capacity){
        include = profit[index] + solveUsingMemo(capacity-wt[index], wt, profit, index+1, n, dp);
    }
    int exclude = 0 + solveUsingMemo(capacity, wt, profit, index+1, n, dp);
    dp[capacity][index] = max(include, exclude);
    // cout << "For capacity: " << capacity << " index: " << index << endl;
    // cout << endl << "Printing dp array: " << endl;
    // printdpArray(dp);
    // cout << endl << endl;
    return dp[capacity][index];
}



int solveUsingTabulation(int capacity, int wt[], int profit[], int n){
    vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));
    // base case analyze kro and initial state fill kro

    for(int row = 0; row <= capacity; row++){
        dp[row][n] = 0;
    }

    // capacity 0 se full ki trf jayegi yha se
    for(int i = 0; i <= capacity; i++){
        for(int j = n-1; j >= 0; j--){
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + dp[i-wt[j]][j+1];
            }
            int exclude = 0 + dp[i][j+1];
            dp[i] [j] = max(include, exclude);
        }
    }
    printdpArray(dp);
    return dp[capacity][0];
}



int solveUsingTabulationSpaceOptmized(int capacity, int wt[], int profit[], int n){

    vector<int> next(capacity+1, 0);
    vector<int> curr(capacity+1, -1);


    // capacity 0 se full ki trf jayegi yha se
    for(int j = n-1; j >= 0; j--){
        for(int i = 0; i <= capacity; i++){
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        cout << endl << endl << "Printing next array" << endl;
        for(int index = 0; index <= capacity; index++){
            cout << next[index] << " ";
        }
        cout << endl;
        // shifting
        next = curr;
    }
    return curr[capacity];
} 


int solveUsingTabulationSpaceOptmized2(int capacity, int wt[], int profit[], int n){

    vector<int> next(capacity+1, 0);


    // capacity 0 se full ki trf jayegi yha se
    for(int j = n-1; j >= 0; j--){
        for(int i = capacity; i >= 0; i--){
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include, exclude);
        }
    }
    return next[capacity];
} 



int main(){
    
    // int capacity = 4;
    // int wt[] = {4,5,1};
    // int profit[] = {1,2,3};
    int capacity = 6;
    int wt[] = {1,2,3};
    int profit[] = {10,15,40};
    int index = 0;
    int n = 3;

    // 2d array depends on capacity and then index(which is from 0 to n)
    vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));
    
    //$ 
    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    // cout << "Max Profit is: " << ans << endl;


    // int ans = solveUsingMemo(capacity, wt, profit, index, n, dp);
    // cout << "Max Profit is: " << ans << endl;

    int ans = solveUsingTabulationSpaceOptmized2(capacity, wt, profit, n);
    cout << "Max Profit is: " << ans << endl;
    return 0;
}