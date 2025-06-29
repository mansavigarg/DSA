// LEETCODE 204 - Count Prime 

// Sieve of Eratosthenes

#include<iostream>
using namespace std;

vector<bool> sieve(int n){
    // create a sieve array of N size telling isPrime
    vector<bool> prime(n+1,true);

    prime[0] = prime[1] = false;

    // ! Optimisation 2 : On outer loop making it to i*i to run from 2 to root(n) 
    for(int i = 2; i*i <= n ; i++){ 
        if(prime[i] == true ){
 

            // * This is without optimization as we are starting form the next number which is 2*i
            for(int j = 2*i; j<=n; j = j+i){
                prime[j] = 0; // making all the multiple of i as non-prime
            }

            //! Optimisation 1: First unnumber number would be i*i as others have been already marked by 2 to i-1
            for(int j = i*i; j<=n; j = j+i){
                prime[j] = 0; // making all the multiple of i as non-prime
            }
        }
    }
    return prime;
}

int main(){
    cout << "Hello " << endl;
    vector<bool> ans = sieve(25);
    for(int i = 0; i <= 25; i++){
        if(ans[i]){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}