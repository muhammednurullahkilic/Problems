#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem 1: Greedy algorithm


struct Meeting {
    int start;
    int end;
    int pos;
};


bool comparator(Meeting m1, Meeting m2) {
    return (m1.end < m2.end);
}

int maxMeetings(int start[], int end[], int N) {
   
    vector<Meeting> meetings(N);
    for (int i = 0; i < N; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }

   
    sort(meetings.begin(), meetings.end(), comparator);

    
    int count = 1;
    int endTime = meetings[0].end;

   
    for (int i = 1; i < N; i++) {
        if (meetings[i].start > endTime) {
            count++;
            endTime = meetings[i].end;
        }
    }

    return count;
}

// Problem 2: Greedy algorithm


struct Job {
    int id;
    int deadline;
    int profit;
};


bool jobComparator(Job j1, Job j2) {
    return (j1.profit > j2.profit);
}

vector<int> JobScheduling(Job arr[], int n) {
   
    sort(arr, arr + n, jobComparator);

    
    vector<bool> slot(n, false);
    int countJobs = 0, maxProfit = 0;

   
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                countJobs++;
                maxProfit += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }

    return { countJobs, maxProfit };
}

int main() {
 
    int start1[] = { 1, 3, 0, 5, 8, 5 };
    int end1[] = { 2, 4, 6, 7, 9, 9 };
    int N1 = 6;
    cout << "Maximum meetings (Problem 1): " << maxMeetings(start1, end1, N1) << endl;

    Job jobs1[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n1 = 4;
    vector<int> result1 = JobScheduling(jobs1, n1);
    cout << "Jobs done (Problem 2): " << result1[0] << ", Maximum profit: " << result1[1] << endl;

    
    Job jobs2[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    int n2 = 5;
    vector<int> result2 = JobScheduling(jobs2, n2);
    cout << "Jobs done (Problem 2): " << result2[0] << ", Maximum profit: " << result2[1] << endl;

    return 0;
}
