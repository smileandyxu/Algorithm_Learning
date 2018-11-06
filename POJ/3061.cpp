/*easy*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
int A[MAXN];
int T, n, S;
int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &S);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &A[i]);
        int ans = INF;
        for (int l = 1, r = 1, t = 0; r <= n; ++r) {
            t += A[r];
            if (t <= 0) {
                l = r + 1;
                t = 0;
            }
            else if (t >= S) {
                while (t - A[l] >= S)
                    t -= A[l++];
                ans = min(ans, r - l + 1);
            }
        }
        if (ans == INF)
            ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
