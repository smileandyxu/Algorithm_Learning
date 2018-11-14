/*An interesting solution from other user from codeforces, which doesn't require segment tree or BIT to maintain a tree.*/
/*Use dfs, calculate the current answer, then minus the addnumbers out of range, which means d(i, j) has been exceeded.*/
#include <bits/stdc++.h>D
#define MAXN 300010
using namespace std;
typedef long long ll;

void input();
void solve();
void output();
void dfs1(ll, ll);
void dfs2(ll, ll);

vector<pair<ll, ll> > A[MAXN];
vector<ll> V[MAXN];
ll D[MAXN], C[MAXN], F[MAXN];
bool vis[MAXN];
ll n, m;

int main()
{
    int size = 192 << 20; //250M
    char*p=(char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p) );
    input();
    solve();
    output();
    return 0;
}
void input()
{
    scanf("%I64d", &n);
    for (ll i = 0, x, y; i != n - 1; ++i) {
        scanf("%I64d%I64d", &x, &y);
        V[x].push_back(y);
        V[y].push_back(x);
    }
    scanf("%I64d", &m);
    for (ll i = 0, v, d, x; i != m; ++i) {
        scanf("%I64d%I64d%I64d", &v, &d, &x);
        A[v].push_back(make_pair(d, x));
    }
}
void solve()
{
    dfs1(1, 0);
    dfs2(1, 0);
}
void output()
{
    for (ll i = 1; i <= n; ++i)
        printf("%I64d ", F[i]);
}
void dfs1(ll i, ll d)
{
    D[i] = d;
    vis[i] = true;
    for (ll j = 0; j != V[i].size(); ++j) {
        if (!vis[V[i][j]])
            dfs1(V[i][j], d + 1);
    }
    vis[i] = false;
}
void dfs2(ll i, ll ans)
{
    vis[i] = true;
    for (ll j = 0; j != A[i].size(); ++j) {
        if (D[i] + A[i][j].first + 1 <= n) {
            C[D[i] + A[i][j].first + 1] += A[i][j].second;
        }
        ans += A[i][j].second;
    }
    F[i] = ans - C[D[i]];
    for (ll j = 0; j != V[i].size(); ++j) {
        if (!vis[V[i][j]])
            dfs2(V[i][j], ans - C[D[i]]);
    }
    for (ll j = 0; j != A[i].size(); ++j) {
        if (D[i] + A[i][j].first + 1 <= n) {
            C[D[i] + A[i][j].first + 1] -= A[i][j].second;
        }
        ans -= A[i][j].second;
    }
    vis[i] = false;
}
