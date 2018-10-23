/*暴力dp。忘了结束点重复的区间了，应该是while不是if。我是傻子。*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXM 1010
#define MAXN 1000010
using namespace std;
struct seg {
    int beg, end, eff;
};
int F[MAXN];
seg A[MAXM];
int n, m, r, ans;
bool cmp(seg x, seg y)
{
    return x.end < y.end;
}
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i != m; ++i)
        scanf("%d%d%d", &A[i].beg, &A[i].end, &A[i].eff);
    sort(A, A + m, cmp);
    for (int i = 1, p = 0; i <= n; ++i) {
        F[i] = F[i - 1];
        while (A[p].end < i && p != m)
            ++p;
        while (A[p].end == i) {
            if (A[p].beg > r)
                F[i] = max(F[i], F[A[p].beg - r] + A[p].eff);
            else
                F[i] = max(F[i], A[p].eff);
            ++p;
        }
    }
    cout << F[n];
    return 0;
}
