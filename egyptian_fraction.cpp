#include <stdio.h>
using namespace std;

/*  Every positive fraction can be represented as sum of unique unit fractions.
    A fraction is unit fraction if numerator is 1 and denominator is a positive integer. For example:

    Egyptian Fraction of 2/3 = 1/2 + 1/6
    Egyptian Fraction of 6/14 = 1/3 + 1/11 + 1/231

    For a given number of the form ‘nr/dr’ where dr > nr, first find the greatest possible unit fraction,
    then recur for the remaining part.

    For example, consider 6/14, we first find ceiling of 14/6, i.e., 3.
    So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42. */

void printEgyptian(int nr, int dr) {
    /*  If either numerator or denominator is 0 */
    if(dr == 0 || nr == 0) return;

    /*  If numerator divides denominator, then simple division
        makes the fraction in 1/n form */
    if(dr % nr == 0) {
        printf("1/%d", dr/nr);
        return;
    }

    /*  If denominator divides numerator, then the given number is not fraction */
    if(nr % dr == 0) {
        printf("%d", nr/dr);
        return;
    }

    /*  If numerator is more than denominator */
    if(nr > dr) {
        printf("%d + ", nr/dr);
        printEgyptian(nr % dr, dr);
        return;
    }

    /*  We reach here dr > nr and dr % nr is non-zero.
        Find ceiling of dr/nr and print it as first fraction. */
    int n = dr/nr + 1;
    printf("1/%d + ", n);

    /* Recur for remaining part */
    printEgyptian(nr*n-dr, dr*n);
 }

int main() {
    int nr = 2, dr = 3;
    printEgyptian(nr, dr);
    return 0;
}
