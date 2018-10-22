/*水题*/
#include <iostream>
#define MAXN 2010
#define MAXL 50
using namespace std;
struct ll {
    int A[MAXL];
    ll &operator+=(const ll &rhs) {
        for (int i = 0, t = 0; i != MAXL; ++i) {
            A[i] += (rhs.A[i] + t);
            t = A[i] / 10;
            A[i] %= 10;
        }
        return *this;
    }
};
ostream &operator<<(ostream &os, const ll &x) {
    int i = MAXL - 1;
    while (i && !x.A[i])
        --i;
    while (i >= 0)
        os << x.A[i--];
}
ll F[MAXN];
int n, k;
int main()
{
    cin >> n >> k;
    F[0].A[0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = i; j <= n; ++j) {
            F[j] += F[j - i];
        }
    }
    cout << F[n];
    return 0;
}
