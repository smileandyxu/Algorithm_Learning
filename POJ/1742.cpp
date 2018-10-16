/*先上一份神奇代码，居然是拿二进制优化过去的：要凑出1至m所有的情况，只需要拿1,2,4等去做就行，因为2可以带上做完3,4可以做完4至7*/
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M(a, b) memset(a, b, sizeof(a))
const int N = 105;
int a[N], num[N];
bool f[100005];
int main() {
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        scanf("%d", &k);
        M(f, 0); f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int sum = num[i] * a[i];
            if (sum >= k) {
                for (int j = a[i]; j <= k; ++j)
                    if (f[j-a[i]]) f[j] = 1;
            }
            else {
                int m = num[i];
                for (int j = 1; j <= m; m-=j, j <<= 1) {
                    int y = j*a[i];
                    for (int x = k; x >= y; --x)
                        if (f[x-y]) f[x] = 1;
                }
                int y = m*a[i];
                for (int x = k; x >= y; --x)
                    if (f[x-y]) f[x] = 1;
            }
        }
        if (f[k]) printf("Yes\n");
        else printf("No\n"); 
    }
    return 0;
}
/*下面是正常一点的解法，用dp记录剩余个数，因为bool转移耗费太大了*/
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXN 110
#define MAXM 100010
using namespace std;
int F[MAXM], A[MAXN], C[MAXN];
int n, m;
int main()
{
    while (scanf("%d%d", &n,&m) && n) {
        memset(F, -1, sizeof(F));
        for (int i = 0; i != n; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i != n; ++i)
            scanf("%d", &C[i]);
        F[0] = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (F[j] >= 0)
                    F[j] = C[i];
                else if (j >= A[i] && F[j - A[i]] > 0)
                    F[j] = F[j - A[i]] - 1;
                else
                    F[j] = -1;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            cnt += (F[i] >= 0);
        printf("%d\n", cnt);
    }
    return 0;
}
/*第二遍自己做，果然代码丑了不少，没必要二维的其实*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define MAXM 100010
#define MAXN 110
using namespace std;

int dp[2][MAXM];
int A[MAXN], C[MAXN];
int n, m;
int main()
{
    while (scanf("%d%d", &n, &m) && n && m) {
        for (int i = 0; i != n; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i != n; ++i)
            scanf("%d", &C[i]);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i != n; ++i) {
            int p = i & 1;
            dp[p][0] = C[i];
            for (int j = 1; j <= m; ++j) {
                if (dp[p ^ 1][j] != -1)
                    dp[p][j] = C[i];
                else
                    dp[p][j] = -1;
                if (j >= A[i] && dp[p][j - A[i]] > 0)
                    dp[p][j] = max(dp[p][j], dp[p][j - A[i]] - 1);
                //cout << i << " " << j << " ==> " << dp[p][j] << endl;
            }
        }
        int cnt = 0;
        for (int j = 1; j <= m; ++j) {
            if (dp[(n - 1) & 1][j] != -1)
                ++cnt;
        }
        printf("%d\n", cnt);
    }


    return 0;
}
