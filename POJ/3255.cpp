/*次短路模板题，坑的一个是它并不是严格的，如果有两条最短路那次短就是最短，再就是注意起始点次短路不是0*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 5010
using namespace std;
struct edge {
    int end, dis;
    edge *next;
    edge(): end(0), dis(0), next(NULL) {}
    edge(int v, int w, edge *e): end(v), dis(w), next(e) {}
};
edge *V[MAXN];
bool B[MAXN];
int D[MAXN][2];
int n, m;
void addedge(int u, int v, int w)
{
    edge *tmp = new edge(v, w, V[u]);
    V[u] = tmp;
}
void spfa()
{
    memset(D, 0x3f, sizeof(D));
    queue<int> Q;
    Q.push(1);
    D[1][0] = 0;
    B[1] = true;
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        B[i] = false;
        for (edge *p = V[i]; p; p = p->next) {
            if (D[i][0] + p->dis < D[p->end][0]) {
                D[p->end][1] = min(D[p->end][1], D[p->end][0]);
                D[p->end][0] = D[i][0] + p->dis;
                if (!B[p->end]) {
                    Q.push(p->end);
                    B[p->end] = true;
                }
            }
            if (D[i][0] + p->dis < D[p->end][1] && D[i][0] + p->dis > D[p->end][0]) {
                D[p->end][1] = D[i][0] + p->dis;
                if (!B[p->end]) {
                    Q.push(p->end);
                    B[p->end] = true;
                }
            }

            if (D[i][1] + p->dis < D[p->end][1] && D[i][1] + p->dis > D[p->end][0]) {
                D[p->end][1] = D[i][1] + p->dis;
                if (!B[p->end]) {
                    Q.push(p->end);
                    B[p->end] = true;
                }
            }
        }
    }

}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i != m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    spfa();
    cout << D[n][1];
    return 0;
}
