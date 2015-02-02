#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;

/*  Given N jobs where every job is represented by following three elements of it.
    1) Start Time
    2) Finish Time.
    3) Profit or Value Associated.
    Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

    Input: n = 4, arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}
    Output: 250 */

/* A job has start time, finish time and profit. */
struct Job {
    int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool myfunction(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

/*  int latestNonConflict(Job arr[], int i) {
        for (int j=i-1; j>=0; j--)
            if (arr[j].finish <= arr[i].start)
                return j;
        return -1;
    }  */

// Using binary search to find the latest job (in sorted array) that doesn't
// conflict with the job[i]
int latestNonConflict(Job arr[], int lo, int hi, int target) {
    int mid;
    while(lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if(arr[mid].finish <= target) lo = mid;
        else hi = mid - 1;
    }

    if(arr[lo].finish > target) return -1;
    return lo;
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n) {
    // Sort jobs according to finish time
    sort(arr, arr+n, myfunction);

    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    int *table = new int[n];
    table[0] = arr[0].profit;

    // Fill entries in M[] using recursive property
    for (int i = 1; i < n; i++) {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        //int l = latestNonConflict(arr, i);
        int l = latestNonConflict(arr, 0, i, arr[i].start);
        if(l != -1) inclProf += table[l];

        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i-1]);
    }

    // Store result and free dynamic memory allocated for table[]
    int result = table[n-1];
    delete[] table;

    return result;
}

int main() {
    //Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n;
    Job j[MAXN];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &j[i].start, &j[i].finish, &j[i].profit);

    printf("%d\n", findMaxProfit(j, n));

    return 0;
}
