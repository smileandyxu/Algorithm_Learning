#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define MAXN 50
#define MAXL 5

bool ispush(char*);

int main()
{
    char opt[MAXL];
    int stk[MAXN], sgn[MAXN];
    int n, i, top;
    scanf("%d", &n);
    top = 0;
    for (i = 0; i != (n << 1); ++i) {
        scanf("%s", &opt);
        if (ispush(opt)) {
            int x;
            scanf("%d", &x);
            sgn[top] = 0;
            stk[top++] = x;
            //printf("%d#\n", top);
        }
        else {
            while (top && sgn[top - 1]) {
                //while (top) {
                    printf("%d", stk[--top]);
                    if (top)
                        printf(" ");
                //}
            }
            if (top) {
                sgn[top - 1] = 1;
            }
        }
    }
    while (top) {
        printf("%d", stk[--top]);
        if (top)
            printf(" ");
    }
    return 0;
}

bool ispush(char *opt)
{
    return (opt[1] == 'u');
}
