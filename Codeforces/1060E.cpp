/*为什么要这么做我也不明白，总之按照边来分析，每条边被子树和它的补走一遍，由于奇+奇=偶+偶=偶，所以奇偶深度之间距离要+1，最后总和/2*/
#include <iostream>
#include <algorithm>
#define MAXN 200010
using namespace std;
typedef long long LL;
struct edge {
    LL end;
    edge *next;
    edge(): end(0), next(NULL) {}
    edge(LL v, edge *e): end(v), next(e) {}
};
edge *V[MAXN];
LL C[MAXN], S[MAXN], B[MAXN];
LL n, ans;
void addedge(LL u, LL v)
{
    edge *tmp = new edge(v, V[u]);
    V[u] = tmp;
}
void dfs1(LL i, LL c)
{
    C[i] = c;
    for (edge *p = V[i]; p; p = p->next) {
        if (C[p->end] == -1) {
            dfs1(p->end, c ^ 1);
            S[i] += S[p->end];
        }
    }
    ++S[i];
}
void dfs2(LL i)
{
    B[i] = true;
    for (edge *p = V[i]; p; p = p->next) {
        if (!B[p->end]) {
            ans += S[p->end] * (n - S[p->end]);
            dfs2(p->end);
        }
    }
}
int main()
{
    cin >> n;
    for (LL i = 0, u, v; i != n - 1; ++i) {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
        C[i + 1] = -1;
    }
    C[n] = -1;
    dfs1(1, 0);
    dfs2(1);
    LL col = 0;
    for (LL i = 1; i <= n; ++i)
        col += C[i];
    ans += col * (n - col);
    cout << ans / 2;
    return 0;
}
