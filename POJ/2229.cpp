/*水题，要注意常数*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXN 1000010
#define MOD 1000000000LL
using namespace std;
typedef long long ll;
ll F[MAXN];
ll n, ans;
int main()
{
    cin >> n;
    F[0] = 1LL;
    for (ll i = 0; (1LL << i) <= n; ++i) {
        for (ll j = (1LL << i); j <= n; ++j) {
            F[j] = (F[j] + F[j - (1LL << i)]);
            while (F[j] >= MOD)
                F[j] -= MOD;
        }
    }
    cout << F[n];
    return 0;
}
