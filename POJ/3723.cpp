/*kruskal模板题*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 50010
using namespace std;
struct edge {
    int beg, end, dis;
};
bool cmp(edge x, edge y)
{
    return x.dis > y.dis;
}
edge E[MAXN];
int P[MAXN];
int T, n, m, r;
int findpa(int x)
{
    if (P[x] == x)
        return x;
    return P[x] = findpa(P[x]);
}
int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &r);
        for (int i = 0; i != r; ++i) {
            scanf("%d%d%d", &E[i].beg, &E[i].end, &E[i].dis);
            E[i].beg += 1;
            E[i].end += 1;
            E[i].end += n;
        }
        sort(E, E + r, cmp);
        for (int i = 1; i <= n + m; ++i)
            P[i] = i;
        int ans = 0;
        for (int i = 0; i != r; ++i) {
            if (findpa(E[i].beg) != findpa(E[i].end)) {
                P[findpa(E[i].beg)] = findpa(E[i].end);
                ans += E[i].dis;

            }
        }
        printf("%d\n", 10000 * (n + m) - ans);
    }

    return 0;
}
