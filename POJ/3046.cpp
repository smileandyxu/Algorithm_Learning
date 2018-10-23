/*A居然这么小就可以水过去。不知道真的范围出的很大该怎么优化……*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXT 1010
#define MAXA 10010
#define MOD 1000000
using namespace std;
int F[2][MAXA];
int N[MAXT];
int T, S, A, B, ans;
void modx(int &x)
{
    while (x < 0)
        x += MOD;
    while (x >= MOD)
        x -= MOD;
}
int main()
{
    scanf("%d%d%d%d", &T, &A, &S, &B);
    for (int i = 0, p; i != A; ++i) {
        scanf("%d", &p);
        ++N[p];
    }
    for (int i = 0; i <= A; ++i)
        F[0][i] = 1;
    F[1][0] = 1;
    for (int i = 1; i <= T; ++i) {
        int p = i & 1;

        for (int j = 1; j <= A; ++j) {
            F[p][j] = F[p ^ 1][j] + F[p][j - 1];
            if (j > N[i])
                F[p][j] -= F[p ^ 1][j - 1 - N[i]];
            modx(F[p][j]);
            //cout << i << "#" << j << "==>" << F[p][j] << endl;
        }
    }
    ans = F[T & 1][B] - F[T & 1][S - 1];
    modx(ans);
    printf("%d", ans);
    return 0;
}
