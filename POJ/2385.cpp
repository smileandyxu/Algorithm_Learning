/*状态函数选择技巧体会：怎么选都有道理，只要不T+好写*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXT 1010
using namespace std;
int dp[MAXT][MAXT][2];
int t, w, ans;
int main()
{
    cin >> t >> w;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    for (int i = 1, p; i <= t; ++i) {
        cin >> p;
        p -= 1;
        for (int q = 0; q != 2; ++q) {
            dp[i][0][q] = min(dp[i - 1][0][q], dp[i - 1][0][q ^ 1] + 1);
            for (int j = 1; j <= t; ++j) {
                dp[i][j][q] = min(dp[i - 1][j][q], dp[i - 1][j][q ^ 1] + 1);
                if (q == p) {
                    dp[i][j][q] = min(dp[i - 1][j - 1][q], dp[i - 1][j - 1][q ^ 1] + 1);
                }
            }
        }
    }
    for (int q = 0; q != 2; ++q) {
        int p = 0;
        while (dp[t][p][q] <= w)
            ++p;
        ans = max(ans, p - 1);
    }
    cout << ans;
    return 0;
}
