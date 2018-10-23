/*LCS模板题。很明显的是去除一个和添加一个字母是完全等价的，那么取cost小的即可。那么很容易想到取反串然后做类似LCS的工作计算最大的无须操作的字符（即公共子串）*/
#include <iostream>
#include <algorithm>
#include <string>
#define MAXM 2010
#define MAXN 256
using namespace std;
string s, t;
int dp[MAXM][MAXM], cost[MAXN];
int n, m, ans;
int main()
{
    cin >> n >> m >> s;
    t = s;
    reverse(t.begin(), t.end());
    for (int i = 0; i != n; ++i) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        cost[c] = min(x, y);
    }
    for (int i = 0; i != s.size(); ++i)
        ans += cost[s[i]];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + cost[s[i - 1]]);
        }
    }
    cout << ans - dp[m][m];
    return 0;
}
