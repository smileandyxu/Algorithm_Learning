/*Just like the classic "Ant Problem", this problem doesn't involve calculation of every collision. Notice the situation that present*/
/*ball is yet to fall after T seconds, in which should print H+2Ri.*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAXN 110
using namespace std;
double fin[MAXN];
double H, R, T;
int N, C;
int main()
{
    cin >> C;
    while (C--) {
        cin >> N >> H >> R >> T;
        R /= 100.0;
        double t = sqrt(H / 5.0);
        for (int i = 0; i != N; ++i) {
            double nt = double(T - i);
            if (nt > 0) {
                int k = nt / t;
                if (k & 1)
                    fin[i] = H - 5.0 * (k * t + t - nt) * (k * t + t - nt);
                else
                    fin[i] = H - 5.0 * (nt - k * t) * (nt - k * t);
                //cout << fin[i] << "#" << endl;
            }
            else
                fin[i] = H;
        }
        sort(fin, fin + N);
        for (int i = 0; i != N; ++i) {
            double ans = i * 2 * R + fin[i];
            printf("%.2f ", ans);
        }
        printf("\n");
    }
    return 0;
}
