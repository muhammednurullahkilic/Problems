#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidAllocation(vector<int>& pages, int n, int m, int max_pages) {
    int students_required = 1;
    int pages_read = 0;

    for (int i = 0; i < n; ++i) {
        if (pages[i] > max_pages) {
            return false;
        }

        if (pages_read + pages[i] > max_pages) {
            students_required++;
            pages_read = pages[i];
        }
        else {
            pages_read += pages[i];
        }

        if (students_required > m) {
            return false;
        }
    }

    return true;
}

int findPages(vector<int>& A, int N, int M) {
    if (N < M) {
        return -1;
    }

    int low = *max_element(A.begin(), A.end()); 
    int high = accumulate(A.begin(), A.end(), 0); 
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValidAllocation(A, N, M, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    
    int N = 4;
    vector<int> A = { 12, 34, 67, 90 };
    int M = 2;
    cout << findPages(A, N, M) << endl;  

    return 0;
}
