#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *A = (int *)a;
    int *B = (int *)b;
    return A[1] - B[1]; //Here 1 is index of finish
}

int main() {
    int n;  /* Number of activities */
    int sf[10][2]; /* Start and finish array */
    int i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d %d", &sf[i][0], &sf[i][1]); /* Start, finish*/

    qsort(sf, n, sizeof(int)*2, cmp);

    for(i = 0; i < n; i++) printf("%d ", sf[i][0]);
    for(i = 0; i < n; i++) printf("%d ", sf[i][1]);

    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++) {
        if (sf[j][0] >= sf[i][1]) {
            printf ("%d ", j);
            i = j;
        }
    }

    return 0;
}
