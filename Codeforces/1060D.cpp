/*神奇贪心*/
#include <iostream>
#include <algorithm>
#define MAXN 100010
using namespace std;
typedef long long LL;
struct man {
    LL l, r, p;
};
man A[MAXN];
man B[MAXN];
bool VIS[MAXN];
LL n, ans;
bool comp1(man x, man y)
{
    return x.l > y.l;
}
bool comp2(man x, man y)
{
    return x.r > y.r;
}
int main()
{
    cin >> n;
    for (LL i = 0; i != n; ++i) {
        cin >> A[i].l >> A[i].r;
        A[i].p = B[i].p = i;
        B[i].l = A[i].l;
        B[i].r = A[i].r;
    }
    sort(A, A + n, comp1);
    sort(B, B + n, comp2);
    for (LL i = 0; i != n; ++i) {
        ans += max(A[i].l, B[i].r) + 1;
    }
    cout << ans;
    return 0;
}
