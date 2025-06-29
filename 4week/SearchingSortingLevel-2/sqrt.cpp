#include<iostream>
#include<iomanip>

using namespace std;

// Function to find integer part of square root
int integerSquareRoot(int n) {
    int s = 0, e = n;
    long long int mid;
    int ans = -1;

    while (s <= e) {
        mid = s + (e - s) / 2;

        // Check if mid * mid == n
        if (mid * mid == n) {
            return mid;
        }

        // If mid * mid < n, move right
        if (mid * mid < n) {
            ans = mid;
            s = mid + 1;
        }
        // Otherwise, move left
        else {
            e = mid - 1;
        }
    }
    return ans;
}

// Function to calculate square root up to 3 decimal places
double squareRoot(int n, int precision) {
    int integerPart = integerSquareRoot(n);
    double increment = 0.1;
    double ans = integerPart;

    // Linear search for decimal places
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= n) {
            ans += increment;
        }
        // Go back one step as loop overshoots
        ans -= increment;
        increment /= 10;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    double result = squareRoot(n, 3);
    cout << "Square root of " << n << " up to 3 decimal places is: " << fixed << setprecision(3) << result << endl;

    return 0;
}
