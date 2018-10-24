/*LIS模板。为什么算思考题呢*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
enum {
    INF = 0x3f3f3f3f,
    MAXN = 40010
};
int F[MAXN];
int A[MAXN];
int T, n, ans;
int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &A[i]);
        memset(F, 0x3f, sizeof(F));
        F[0] = 0;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            int p = lower_bound(F, F + n + 1, A[i]) - F;
            F[p] = A[i];
            ans = max(ans, p);
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
7
9 48 29 2 26 21 9 35 4 25 45 16 26 42
*/
