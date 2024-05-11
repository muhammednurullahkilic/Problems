#include <iostream>
#include <algorithm>
using namespace std;

struct Pair {
    int a, b;
};

bool comparePairs(const Pair& x, const Pair& y) {
    return x.a < y.a;
}

int maxChainLen(Pair arr[], int n) {
    sort(arr, arr + n, comparePairs); // Sort pairs based on the first element

    int dp[n]; // Dynamic programming array

    // Initialize dp[i] = 1 for all pairs
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // Dynamic programming approach to find the longest chain
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].b < arr[i].a) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in dp[] array
    int maxLength = dp[0];
    for (int i = 1; i < n; i++) {
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest chain: " << maxChainLen(arr, n) << endl;
    return 0;
}
