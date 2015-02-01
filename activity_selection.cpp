#include<stdio.h>

/*  Given N activities with their start and finish times. Select the maximum number of activities that can
    be performed by a single person, assuming that a person can only work on a single activity at a time.

    Consider the following 6 activities.
        start[]  =  {1, 3, 0, 5, 8, 5};
        finish[] =  {2, 4, 6, 7, 9, 9};
        Output:     {0, 1, 3, 4} */

/*  Prints a maximum set of activities that can be done by a single person, one at a time.
    n   -->  Total number of activities
    s[] -->  An array that contains start time of all activities
    f[] -->  An array that contains finish time of all activities */
void printActivities(int s[], int f[], int n) {
    int i, j;

    /*  The first activity will always be selected */
    i = 0;
    printf("%d ", i);

    /*  Consider rest of the activities */
    for(j = 1; j < n; j++) {
        /* If this activity has start time greater than or equal to the finish
        time of previously selected activity, then select it */
        if(s[j] >= f[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);

    printActivities(s, f, n);
    return 0;
}
