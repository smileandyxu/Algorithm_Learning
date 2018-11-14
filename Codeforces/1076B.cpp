/*Another simple problem, not solved because of my stupid. Any prime divisor, except 2, is odd. Any given number, which is not even, */
/*will be even after being subtracted by an odd number, then it has divisor 2. Then however times it is subtracted it will still hold */
/*this divisor. Therefore the result is 1+(n-d)/2.*/
#include <bits/stdc++.h>
#define MAXN 200010
#define MAXM 1000010
using namespace std;
typedef long long ll;

ll n, ans;

void input();
void solve();
void output();
void init();

int main()
{
    input();
    solve();
    output();
    return 0;
}
void input()
{
    cin >> n;
}
void solve()
{
    ll d = 2;
    while (d * d <= n) {
        if (n % d == 0)
            break;
        ++d;
    }
    if (n % d != 0)
        ans = 1;
    else
        ans = 1 + (n - d) / 2;
}
void output()
{
    cout << ans;
}
