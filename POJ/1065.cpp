/*偏序定理转为严格最长下降子序列。为了方便reverse然后打LIS模板。*/
/*要注意的是cmp的定义：第一次按第一关键字排序务必将第二关键字倒序，这样在做dp的时候更新的一定更小。*/
/*要绕清楚lowerbound和upperbound，<和<=以及两个关键字的排序。AC简直就是奇迹了。*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXS 10010
#define MAXN 5010
using namespace std;
struct pt {
    int x, y;
};
bool cmp2(const pt &lhs, const pt &rhs) {
    return ((lhs.x < rhs.x) && (lhs.y < rhs.y));
}
bool cmp(const pt &lhs, const pt &rhs)
{
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y > rhs.y);
}
pt A[MAXN];
pt F[MAXN];
int T, n, ans;
int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i].x >> A[i].y;
            A[i].x = MAXS - A[i].x;
        }
        sort(A + 1, A + n + 1, cmp);
        for (int i = 1; i <= n + 1; ++i)
            F[i].x = F[i].y = INF;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            int p = lower_bound(F, F + n + 1, A[i], cmp2) - F;
            F[p].x = A[i].x;
            F[p].y = A[i].y;
            ans = max(ans, p);
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
7
9 48 29 2 26 21 9 35 4 25 45 16 26 42
*/
