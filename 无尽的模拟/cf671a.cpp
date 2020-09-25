#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;
double x[maxn], y[maxn];
double f[maxn], g[maxn], h[maxn];
double ax, ay, bx, by, tx, ty;
int n;
double sumal;
void getmind(int& ind1, int& ind2, double* h) {
    double mind1 = 9999999999990, mind2 = 9999999999990;
    for (int i = 1;i <= n;i++) {
        if (h[i] - f[i] < mind1) {
            mind2 = mind1;
            ind2 = ind1;
            mind1 = h[i] - f[i];
            ind1 = i;
        }
        else if (h[i] - f[i] < mind2) {
            mind2 = h[i] - f[i];
            ind2 = i;
        }
    }
}
int main() {
    freopen("data.in", "r", stdin);
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x[i] >> y[i];
        f[i] = sqrt(1.0 * (x[i] - tx) * (x[i] - tx) + 1.0 * (y[i] - ty) * (y[i] - ty));
        g[i] = sqrt(1.0 * (x[i] - ax) * (x[i] - ax) + 1.0 * (y[i] - ay) * (y[i] - ay));
        h[i] = sqrt(1.0 * (x[i] - bx) * (x[i] - bx) + 1.0 * (y[i] - by) * (y[i] - by));
        sumal += 2.0 * f[i];
    }

    if (n == 1) {
        printf("%.7lf\n", min(g[1], h[1]) + f[1]);
    }
    else {

        int indh1, indh2;
        int indg1, indg2;
        getmind(indh1, indh2, h);
        getmind(indg1, indg2, g);

        if (h[indh1] - f[indh1] < 0 && g[indg1] - f[indg1] < 0) {
            if (indh1 != indg1) {
                printf("%.9lf", sumal - f[indh1] - f[indg1] + h[indh1] + g[indg1]);
            }
            else {

                double lt1 = sumal - f[indh2] - f[indg1] + h[indh2] + g[indg1];
                double lt2 = sumal - f[indh1] - f[indg2] + h[indh1] + g[indg2];
                printf("%.9lf", min(lt1, lt2));
            }
        }
        else {
            double ans;
            if (h[indh1] - f[indh1] < g[indg1] - f[indg1]) {
                ans = sumal + h[indh1] - f[indh1];
            }
            else {
                ans = sumal + g[indg1] - f[indg1];
            }
            printf("%.9lf\n", ans);
        }

    }

    return 0;
}