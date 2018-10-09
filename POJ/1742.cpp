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
/*下面是正常一点的解法*/
