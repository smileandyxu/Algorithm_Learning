/*离散化，dp。应该是经典题了，以前一直没做出来。圆梦离散化*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
enum {
    //INF = 0x3f3f3f3f,
    MAXN = 2010,
    MAXL = 2010
};
struct hil {
    int h, p;
};
int F[2][MAXL], D[MAXL];
hil A[MAXN];
int H[MAXL];
int n, ans, m;
bool cmph(hil x, hil y)
{
    return x.h < y.h;
}
bool cmp1(hil x, hil y)
{
    return x.p < y.p;
}
bool cmp2(hil x, hil y)
{
    return x.p > y.p;
}
int cost(int i, int j)
{
    return abs(H[j] - H[A[i].h]);
}
void work()
{
    memset(F, 0x3f, sizeof(F));
    D[0] = INF;
    for (int i = 1; i <= m; ++i) {
        F[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            F[i & 1][j] = min(INF, D[j] + cost(i, j));
        }
        for (int j = 1; j <= m; ++j)
            D[j] = min(D[j - 1], F[i & 1][j]);
    }
    ans = min(ans, D[m]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i].h);
        A[i].p = i;
    }
    sort(A + 1, A + n + 1, cmph);
    for (int i = 1; i <= n; ++i) {
        H[i] = A[i].h;
        A[i].h = i;
    }
    m = n;
    ans = INF;
    sort(A + 1, A + n + 1, cmp1);
    work();
    sort(A + 1, A + n + 1, cmp2);
    work();
    cout << ans;
    return 0;
}
