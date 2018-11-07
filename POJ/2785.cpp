/*Remember that one value might appear more than once! Use upper_bound-lower_bound to calculate the times it appears.*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAXN 4010
using namespace std;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN], S[MAXN * MAXN];
int n, tot, cnt;
int main()
{
    cin >> n;
    for (int i = 0; i != n; ++i)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            S[tot++] = -C[i] - D[j];
        }
    }
    sort(S, S + tot);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            cnt += (upper_bound(S, S + tot, A[i] + B[j]) - lower_bound(S, S + tot, A[i] + B[j]));
        }
    }
    cout << cnt;
    return 0;
}
