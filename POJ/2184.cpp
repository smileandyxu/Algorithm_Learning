/*easy*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 100;
const int MAXS = 200100;
const int MINS = 100020;
const int INF = 0x3f3f3f3f;

int S[MAXN], F[MAXN], G[2][MAXS];
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> S[i] >> F[i];
    for (int i = 0; i <= MAXS - 1; ++i)
        G[0][i] = -INF;
    G[0][MINS] = 0;
    for (int i = 1; i <= n; ++i) {
        int p = i & 1;
        for (int j = 0; j <= MAXS - 1; ++j)
            G[p][j] = G[p ^ 1][j];
        for (int j = max(S[i], 0); j <= MAXS - 1; ++j) {
            if (j - S[i] <= MAXS - 1 && G[p ^ 1][j - S[i]] != -INF)
                G[p][j] = max(G[p ^ 1][j], G[p ^ 1][j - S[i]] + F[i]);
        //if (G[p][j] != -INF)
        //cout << i << "#" << j - MINS << " " << G[p][j] << endl;
        }
    }
    for (int i = MINS; i <= MAXS - 1; ++i)
        if (G[n & 1][i] >= 0)
            ans = max(ans, G[n & 1][i] + i - MINS);
    cout << ans;
    return 0;
}
