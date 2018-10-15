/*差分约束。要注意的是-1和-2的判定条件。不知道怎么调就AC了，明明一个字都没改……*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 20010
using namespace std;
typedef long long LL;
LL U[MAXN], V[MAXN], W[MAXN], D[MAXN];
LL n, ml, md, m;

int main()
{

    scanf("%lld%lld%lld", &n, &ml, &md);
    fill(D + 1, D + n + 1, INF);
    m = ml + md;
    for (LL i = 0, u, v, w; i != ml; ++i) {
        scanf("%lld%lld%lld", &u, &v, &w);
        U[i] = u;
        V[i] = v;
        W[i] = w;
    }
    for (LL i = 0, u, v, w; i != md; ++i) {
        scanf("%lld%lld%lld", &u, &v, &w);
        U[ml + i] = v;
        V[ml + i] = u;
        W[ml + i] = -w;
    }
    for (LL i = 1; i < n; ++i) {
        U[m] = i + 1;
        V[m] = i;
        W[m++] = 0;
    }
    D[1] = 0;
    LL flag = 0;
    for (LL i = 0; i <= n; ++i) {
        bool updated = false;
        /*for (int k = 1; k <= n; ++k)
            cout << D[k] << " ";
        cout << endl;*/
        for (LL j = 0; j != m && !flag; ++j) {
            if (D[U[j]] + W[j] < D[V[j]]) {
                D[V[j]] = D[U[j]] + W[j];
                updated = true;
                if (i == n)
                    flag = -1;
            }
        }
        if (!updated)
            break;
    }

    if (flag != -1 && D[n] == INF)
        flag = -2;
    if (flag != 0)
        cout << flag;
    else
        cout << D[n];
    return 0;
}
