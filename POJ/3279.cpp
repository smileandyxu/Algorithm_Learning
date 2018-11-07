/*An interesting method. First we notice that M and N is confined to 15, which suggests us use dfs. After enumerating the*/
/*flipping possibilities, we can calculate the condition of next line quickly. Then we only need to check if the last line*/
/*is legal. Notice that the lexicographical order is from the right side, which means we have to search from the rightest*/
/*place. Or we can use binary number representing the set, regardless of its complexity in writing.*/
#include <iostream>
#define MAXN 18
#define opt 5
using namespace std;
const int dx[opt] = {0, 1, 0, -1, 0};
const int dy[opt] = {0, 0, 1, 0, -1};
bool tile[MAXN][MAXN];
int flip[MAXN][MAXN];
int m, n;
bool flag;
bool get(int i, int j)
{
    bool b = tile[i][j];
    for (int k = 0; k != opt; ++k)
        b ^= (flip[i + dx[k]][j + dy[k]]);
    return b;
}
bool calc()
{
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (get(i, j)) {
                ++flip[i + 1][j];
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        if (get(m, j)) {
            return false;
        }
    }
    return true;
}
void clean()
{
    for (int i = 2; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            flip[i][j] = 0;
}
void dfs(int k)
{
    if (flag)
        return;
    else if (k == 0) {
        int p = calc();
        if (p) {
            flag = true;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j)
                    cout << flip[i][j] << " ";
                cout << endl;
            }
        }
        clean();
    }
    else {
        flip[1][k] = 0;
        dfs(k - 1);
        flip[1][k] = 1;
        dfs(k - 1);
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> tile[i][j];
        }
    }
    flag = false;
    dfs(n);
    if (!flag)
        cout << "IMPOSSIBLE";
    return 0;
}
