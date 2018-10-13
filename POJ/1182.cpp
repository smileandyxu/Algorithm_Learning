/*食物链重打，练代码。倒是没想到poj老人机连150k的输入都不能用iostream*/
#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXN 50010
using namespace std;
int P[MAXN * 3];
int n, k;
int findpa(int x)
{
    if (P[x] == x)
        return x;
    return P[x] = findpa(P[x]);
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n * 3; ++i) {
        P[i] = i;
    }
    int cnt = 0;
    while (k--) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x < 1 || x > n || y < 1 || y > n) {
            ++cnt;
            continue;
        }
        if (d == 1) {
            if (findpa(x) == findpa(y + n) || findpa(x) == findpa(y + 2 * n))
                ++cnt;
            else {
                P[findpa(x)] = findpa(y);
                P[findpa(x + n)] = findpa(y + n);
                P[findpa(x + 2 * n)] = findpa(y + 2 * n);
            }
        }
        else {
            if (findpa(x) == findpa(y) || findpa(x) == findpa(y + 2 * n))
                ++cnt;
            else {
                P[findpa(x)] = findpa(y + n);
                P[findpa(x + n)] = findpa(y + 2 * n);
                P[findpa(x + 2 * n)] = findpa(y);
            }
        }
    }
    cout << cnt;
    return 0;
}
