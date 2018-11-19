#include <stdio.h>
#include <stdbool.h>
#define MAXN 1020

int stk[MAXN], num[MAXN];
int m, n, k, top;

int main()
{
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        int i, j;
        for (i = 0; i != n; ++i)
            scanf("%d", &num[i]);
        bool flag = true;
        for (i = 1, j = 0, top = 0; i <= n && flag; ++i) {
            stk[top++] = i;
            if (top > m)
                flag = false;
            while (flag && top && stk[top - 1] == num[j]) {
                //printf("(%d, %d)\n", stk[top - 1], num[j]);
                --top;
                ++j;
            }

        }
        if (top)
            flag = false;
        printf(flag ? "YES" : "NO");
        if (k)
            printf("\n");
    }
    return 0;
}
