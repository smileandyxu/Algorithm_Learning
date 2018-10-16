/*水题*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXN 500
using namespace std;

int F[MAXN][MAXN];
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> F[i][j];
            F[i][j] += max(F[i - 1][j - 1], F[i - 1][j]);
            ans = max(ans, F[i][j]);
        }
    }
    cout << ans;
    return 0;
}
