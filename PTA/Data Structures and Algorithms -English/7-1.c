#include <stdio.h>
enum {
    MAXN = 10010
};
int A[MAXN];
int n, i, l, r, lx, rx, tmp, sum;
int main()
{
    scanf("%d", &n);
    for (i = 0; i != n; ++i)
        scanf("%d", &A[i]);
    lx = A[0];
    rx = A[n - 1];
    for (r = 0; r != n; ++r) {
        tmp += A[r];
        if (tmp < 0) {
            l = r + 1;
            tmp = 0;
        }
        else if (tmp > sum || (tmp == 0 && sum == 0)) {
            sum = tmp;
            lx = A[l];
            rx = A[r];
        }
    }
    printf("%d %d %d", sum, lx, rx);
    return 0;
}
