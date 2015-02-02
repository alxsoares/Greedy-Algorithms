#include<iostream>
#include<algorithm>
using namespace std;

/*  Given an array of jobs where every job has a deadline and associated profit if the job is finished
    before the deadline. It is also given that every job takes single unit of time, so the minimum possible
    deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

    Input: Four Jobs with following deadlines and profits
    JobID    Deadline       Profit
    a        4              20
    b        1              10
    c        1              40
    d        1              30
    Output: c, a */

struct Job {
   char id;         /* Job Id */
   int dead;        /* Deadline of job */
   int profit;      /* Profit if job is over before or on deadline */
};

/* Function for sorting all jobs according to profit */
bool comparison(Job a, Job b) {
     return (a.profit > b.profit);
}

/* Returns minimum number of platforms recquired */
void printJobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of prfit
    sort(arr, arr+n, comparison);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots

    // Initialize all slots to be free
    for(int i = 0; i < n; i++) slot[i] = false;

    // Iterate through all given jobs
    for(int i = 0; i < n; i++) {
       // Find a free slot for this job (Note that we start
       // from the last possible slot)
        for(int j = min(n, arr[i].dead)-1; j>=0; j--) {
        // Free slot found
            if(slot[j]==false) {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
       if(slot[i]) cout << arr[result[i]].id << " ";
}

int main() {
    Job arr[5] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printJobScheduling(arr, n);
    return 0;
}
