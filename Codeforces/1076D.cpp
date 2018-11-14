/*The first solution came to me was Prim Algorithm. However during the round I wasn't able to write it. In fact we can consider */
/*Dijkstra Algorithm instead, since they are actually close to each other. Do dijkstra K times and we can get the answer.*/
/*Remember to use pair<> in c++, which is far more convenient than writing a structure by own.*/
#include <bits/stdc++.h>
#define INF 1e15
#define MAXN 300010
using namespace std;
typedef long long ll;
struct edge {
    int end, len, num;
    edge *next;
    edge(): end(0), len(0), num(0), next(NULL) {}
    edge(ll v, ll w, ll i, edge *e): end(v), len(w), num(i), next(e) {}
};

edge *V[MAXN];
bool vis[MAXN];
ll D[MAXN], A[MAXN];
ll n, m, k, tot;

void input();
void solve();
void output();
void addedge(ll u, ll v, ll w, ll i)
{
    edge *tmp = new edge(v, w, i, V[u]);
    V[u] = tmp;
}

int main()
{
    input();
    solve();
    output();
    return 0;
}
void input()
{
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    for (ll i = 1, u, v, w; i <= m; ++i) {
        scanf("%I64d%I64d%I64d", &u, &v, &w);
        addedge(u, v, w, i);
        addedge(v, u, w, i);
    }
}
void solve()
{
    for (int i = 2; i <= n; ++i)
        D[i] = INF;
    static set<pair<ll, pair<ll, ll> > > Q;
    Q.insert(make_pair(0, make_pair(1, 0)));
    for (ll i = 0; i != k + 1 && !Q.empty(); ++i) {
        while (vis[Q.begin()->second.first])
            Q.erase(Q.begin());
        if (Q.empty())
            break;
        ll t = Q.begin()->second.first;
        vis[t] = true;
        if (t != 1) {
            A[tot++] = Q.begin()->second.second;
        }
        Q.erase(Q.begin());
        for (edge *p = V[t]; p; p = p->next) {
            if (D[t] + p->len < D[p->end]) {
                D[p->end] = D[t] + p->len;
                Q.insert(make_pair(D[p->end], make_pair(p->end, p->num)));
            }
        }
    }

}
void output()
{
    printf("%I64d\n", tot);
    for (ll i = 0; i != tot; ++i)
        printf("%I64d ", A[i]);
}
