/*Remember the situation that the answer must appear in a given set*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MAXN = 100010;
const ll INF = 0x3f3f3f3f;
ll X[MAXN];
ll n, c, ans;
int can(ll len)
{
    ll cnt = 0;
    ll pre = -INF;
    ll mind = INF;
    for (ll i = 0; i != n; ++i) {
        if (cnt == c)
            break;
        if (X[i] - pre >= len) {
            mind = min(mind, X[i] - pre);
            pre = X[i];
            ++cnt;
        }
    }
    return (cnt == c ? mind : 0);
}
int main()
{
    cin >> n >> c;
    for (ll i = 0; i != n; ++i) {
        scanf("%I64d", &X[i]);
    }
    sort(X, X + n);

    ll lb = 0, rb = 1000000010;
    while (lb <= rb) {
        ll mb = (lb + rb) >> 1;
        int dd = can(mb);
        if (dd)  {
            ans = dd;
            lb = mb + 1;
        }
        else
            rb = mb - 1;
    }
    cout << ans;
    return 0;
}
