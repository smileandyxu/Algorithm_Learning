/*七弯八绕绕过来就好了，水dp，但当时就是没想通让它走了捷径*/
#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
typedef long long LL;
struct poLL {
    LL x, y, l;
    poLL &operator=(const poLL rhs) {
        x = rhs.x;
        y = rhs.y;
        l = rhs.l;
        return *this;
    }
};
LL dis(poLL a, poLL b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}
LL level(poLL a)
{
    return max(a.x, a.y);
}
bool cmp(poLL a, poLL b)
{
    return (a.l < b.l) || (a.l == b.l && a.x < b.x) || (a.l == b.l && a.x == b.x && a.y > b.y);
}

poLL A[MAXN], P[MAXN][2];
LL dp[MAXN][2];
LL n, tot;

int main()
{
    scanf("%I64d", &n);
    for (LL i = 0; i != n; ++i) {
        scanf("%I64d%I64d", &A[i].x, &A[i].y);
        A[i].l = level(A[i]);
    }
    sort(A, A + n, cmp);
    tot = 1;
    for (LL i = 0, ll = -1; i <= n; ++i) {
        if (A[i].l != ll) {
            ll = A[i].l;
            P[tot][0] = A[i];
        }
        if (A[i + 1].l != ll) {
            P[tot++][1] = A[i];
        }
    }
    //cout << tot - 1 << endl;
    for (LL i = 1; i != tot; ++i) {
        dp[i][0] = min(dp[i - 1][1] + dis(P[i - 1][1], P[i][1]) + dis(P[i][0], P[i][1]),
                       dp[i - 1][0] + dis(P[i - 1][0], P[i][1]) + dis(P[i][0], P[i][1]));
        dp[i][1] = min(dp[i - 1][0] + dis(P[i - 1][0], P[i][0]) + dis(P[i][0], P[i][1]),
                       dp[i - 1][1] + dis(P[i - 1][1], P[i][0]) + dis(P[i][0], P[i][1]));
        //cout << i << ":" << P[i][0].x << "," << P[i][0].y << " " << P[i][1].x << "," << P[i][1].y << " ==> " << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[tot - 1][0], dp[tot - 1][1]);
    return 0;
}
