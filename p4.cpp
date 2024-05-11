#include <iostream>
#include <algorithm>
using namespace std;

struct Pair {
    int a, b;
};

bool comparePairs(const Pair& x, const Pair& y) {
    return x.b < y.b;
}

int maxChainLen(Pair arr[], int n) {
    
    sort(arr, arr + n, comparePairs);

    int maxLength = 1; 
    int end = arr[0].b; 

    
    for (int i = 1; i < n; i++) {
        
        if (arr[i].a > end) {
            maxLength++;
            end = arr[i].b;
        }
    }

    return maxLength;
}

int main() {
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest chain: " << maxChainLen(arr, n) << endl;
    return 0;
}
