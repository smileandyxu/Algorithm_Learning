/*easy*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
inline int getint()
{
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
map<int, int> M;
int A[MAXN];
int n, ans, m;
int main()
{
    n = getint();
    for (int i = 1; i <= n; ++i) {
        A[i] = getint();
        ++M[A[i]];
    }
    m = M.size();
    M.clear();
    ans = INF;
    for (int l = 1, r = 1, t = 0; r <= n; ++r) {
        if (M[A[r]]++ == 0)
            ++t;
        while (t == m && M[A[l]] > 1) {
            --M[A[l++]];
        }
        if (t == m)
            ans = min(ans, r - l + 1);
    }
    printf("%d", ans);
    return 0;
}
