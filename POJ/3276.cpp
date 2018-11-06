/*Firstly we can draw a conclusion that enumerating the value of K is necessary, and to check whether it is valid we have to simulate*/
/*the reversal process. That made the algorithm O(n^2), so we have to find a O(1) way to build the check. We use F[i] which refers to*/
/*if this position, as a head, has been reversed. Thus by using prefix sum we can easily calculate the status of the present point and*/
/*decide if we have to reverse it.*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 5010;
int S[MAXN], F[MAXN];
bool B[MAXN];
int n, minopt, minans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        B[i] = (c == 'F');
    }
    minopt = minans = INF;
    for (int k = 1; k <= n; ++k) {
        memset(F, 0, sizeof(F));
        memset(S, 0, sizeof(S));
        int cnt = 0;
        //cout << "#" << k << "#" << endl;
        for (int i = 1; i <= n - k + 1; ++i) {
            F[i] = S[i - 1];
            if (i - k + 1 >= 0)
                F[i] -= S[i - k];
            if (B[i] ^ (F[i] & 1))
                F[i] = 0;
            else {
                F[i] = 1;
                ++cnt;
                //cout << i << " " << B[i] << " " << F[i] << endl;
            }
            S[i] = S[i - 1] + F[i];
        }
        for (int i = n - k + 2; i <= n; ++i) {
            F[i] = S[i - 1];
            if (i - k + 1 >= 0)
                F[i] -= S[i - k];
            if (!(B[i] ^ (F[i] & 1))) {
                cnt = -1;
                break;
            }
            S[i] = S[i - 1];
        }
        if (cnt != -1) {
            if (cnt < minopt) {
                minopt = cnt;
                minans = k;
            }
        }
    }
    cout << minans << " " << minopt;
    return 0;
}
