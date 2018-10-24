/*我真傻。只要简单贪心一下a，剩下的就是多重背包裸题。别怕1e7的数据*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
enum {
    INF = 0x3f3f3f3f,
    MAXM = 40010,
    MAXN = 4010
};
struct obj {
    int h, a, c;
};
obj A[MAXN];
int F[MAXM];
int K, m, ans;
bool cmp(obj x, obj y)
{
    return x.a < y.a;
}
int main()
{
    cin >> K;
    for (int i = 0; i != K; ++i)
        cin >> A[i].h >> A[i].a >> A[i].c;
    m = MAXM - 1;
    memset(F, -1, sizeof(F));
    F[0] = 0;
    sort(A, A + K, cmp);
    for (int i = 0; i != K; ++i) {
        //cout << A[i].h << "==>";
        for (int j = 0; j <= A[i].a; ++j) {
            if (F[j] != -1) {
                F[j] = A[i].c;
            }
            else if (j >= A[i].h && F[j - A[i].h] > 0) {
                F[j] = F[j - A[i].h] - 1;
                //cout << "(" << j << ", " << F[j] << ") ";
            }
        }
        //cout << endl;
    }
    for (int j = m; j >= 1; --j) {
        if (F[j] != -1) {
            ans = j;
            break;
        }
    }
    cout << ans;
    return 0;
}
