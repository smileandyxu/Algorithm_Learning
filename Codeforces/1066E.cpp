/*写了半天WA，发现存反了。我是傻子。*/
#include <bits/stdc++.h>
#define MOD 998244353LL
#define MAXN 200010
using namespace std;
typedef long long ll;
ll A[MAXN], B[MAXN], C[MAXN];
ll n, m, ans;
ll getll()
{
    char c;
    do {
        c = getchar();
    } while (!isdigit(c));
    return c - '0';
}
ll mypow(ll k)
{
    ll s = 1, t = 2;
    while (k) {
        if (k & 1)
            s = (s * t) % MOD;
        t = (t * t) % MOD;
        k >>= 1;
    }
    return s;
}
int main()
{
    cin >> n >> m;
    for (ll i = n - 1; i >= 0; --i)
        A[i] = getll();
    for (ll i = 0; i != m; ++i)
        B[i] = getll();
    C[0] = A[0] * mypow(0) % MOD;
    for (ll i = 1; i != m; ++i)
        C[i] = (C[i - 1] + A[i] * mypow(i)) % MOD;
    for (ll i = 0; i != m; ++i)
        ans = (ans + (B[i] ? C[m - i - 1] : 0)) % MOD;
    cout << ans;
    return 0;
}
