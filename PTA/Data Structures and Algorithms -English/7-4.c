#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define MAXN 20
#define END -1

int getson();
int getroot();
bool isleaf(int);
void putarr();

int lc[MAXN], rc[MAXN], A[MAXN], Q[MAXN];
bool vis[MAXN];
int n, tot, head, tail, root;

int main()
{
    int i;
    scanf("%d", &n);
    for (i = 0; i != n; ++i) {
        lc[i] = getson();
        rc[i] = getson();
        if (lc[i] != END)
            vis[lc[i]] = true;
        if (rc[i] != END)
            vis[rc[i]] = true;
    }
    root = getroot();
    Q[tail++] = root;
    while (head != tail) {
        int x = Q[head++];
        if (x == -1)
            continue;
        if (isleaf(x))
            A[tot++] = x;
        if (lc[x] != END)
            Q[tail++] = lc[x];
        if (rc[x] != END)
            Q[tail++] = rc[x];
    }
    putarr();
    return 0;
}

int getson()
{
    int x = END;
    char c = getchar();
    while (!isdigit(c) && c != '-')
        c = getchar();
    while (isdigit(c)) {
        if (x == END)
            x = 0;
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int getroot()
{
    int i;
    for (i = 0; i != n; ++i) {
        if (!vis[i])
            return i;
    }
    return -1;
}
bool isleaf(int i)
{
    return (lc[i] == rc[i] && lc[i] == END);
}
void putarr()
{
    int i;
    for (i = 0; i != tot; ++i) {
        printf("%d", A[i]);
        if (i != tot - 1)
            printf(" ");
    }
}
