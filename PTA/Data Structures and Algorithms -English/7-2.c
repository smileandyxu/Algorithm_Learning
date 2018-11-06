/*I've never thought about it that a given node can be not in the list(. Well, you win.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAXN 100010

int val[MAXN], next[MAXN];
bool vis[MAXN];
int n, head, k;
int main()
{
    int i, j, p, v, q, r, cnt;
    scanf("%d%d%d", &head, &n, &k);
    for (i = 0; i != n; ++i) {
        scanf("%d%d%d", &p, &v, &q);
        val[p] = v;
        next[p] = q;
    }
    for (i = head; i != -1; i = next[i])
        vis[i] = true;
    for (i = 1, p = head, q = head, cnt = 1, r = -1; i <= n; ++i) {
        if (!vis[q])
            continue;
        else {
            //printf("#%d#\n", i);
            if (cnt % k == 0) {
                if (cnt == k)
                    head = q;
                if (r != -1)
                    next[r] = q;
                j = p;
                int s = next[q];
                r = s;
                while (j != s) {
                    int t = next[j];
                    next[j] = r;
                    r = j;
                    j = t;
                }
                r = p;
                p = s;
                q = p;
                //printf("###");
            }
            else
                q = next[q];
            ++cnt;
        }
    }
    for (i = head; i != -1; i = next[i]) {
        printf("%05d %d ", i, val[i]);
        if (next[i] == -1)
            printf("-1");
        else
            printf("%05d\n", next[i]);
    }
    return 0;
}
/*
00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
