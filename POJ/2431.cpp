/*没想到的思路：变换思考方式，到达加油站意味着“获得一次加油的机会”而不需要直接开始选择是否加油。到必须要加油的时候选择最大油量的站即可*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 10010
using namespace std;
struct station {
    int dis, gas;
};
station A[MAXN];
int N, L, P;
bool cmp(station x, station y)
{
    return x.dis < y.dis;
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &A[i].dis, &A[i].gas);
    scanf("%d%d", &L, &P);
    for (int i = 1; i <= N; ++i)
        A[i].dis = L - A[i].dis;

    sort(A + 1, A + N + 1, cmp);
    int cnt = 0;
    priority_queue<int> F;
    bool flag = true;
    A[N + 1].dis = L;
    for (int i = 1; i <= N + 1 && flag; ++i) {
        int d = A[i].dis - A[i - 1].dis;
        while (P < d && flag) {
            if (F.empty())
                flag = false;
            else {
                P += F.top();
                F.pop();
                ++cnt;
            }
        }
        P -= d;
        F.push(A[i].gas);
    }

    if (!flag)
        printf("-1");
    else
        printf("%d", cnt);

    return 0;
}
