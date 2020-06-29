#include <iostream>
#include <cstdio>
using namespace std;
int col[2][2];

void merge(int xi, int yi, int k, int gx, int gy)
{

    if (k == 0)
        return;
    //printf("k= %d gx= %d gy= %d\n", k, gx, gy);
    int m, n;
    int len = 1 << (k - 1);
    m = (gx - xi) / len;
    n = (gy - yi) / len;

    int ansx = xi + len - m;
    int ansy = yi + len - n;
    printf("%d %d %d\n", ansx, ansy, col[m][n]);
    if (m == 0 && n == 0)
    {
        merge(xi, yi, k - 1, gx, gy);
        merge(xi, yi + len, k - 1, xi + len - 1, yi + len);
        merge(xi + len, yi, k - 1, xi + len, yi + len - 1);
        merge(xi + len, yi + len, k - 1, xi + len, yi + len);
    }
    else if (m == 0 && n == 1)
    {
        merge(xi, yi, k - 1, xi + len - 1, yi + len - 1);
        merge(xi, yi + len, k - 1, gx, gy);
        merge(xi + len, yi, k - 1, xi + len, yi + len - 1);
        merge(xi + len, yi + len, k - 1, xi + len, yi + len);
    }
    else if (m == 1 && n == 0)
    {
        merge(xi, yi, k - 1, xi + len - 1, yi + len - 1);
        merge(xi, yi + len, k - 1, xi + len - 1, yi + len);
        merge(xi + len, yi, k - 1, gx, gy);
        merge(xi + len, yi + len, k - 1, xi + len, yi + len);
    }
    else if (m == 1 && n == 1)
    {
        merge(xi, yi, k - 1, xi + len - 1, yi + len - 1);
        merge(xi, yi + len, k - 1, xi + len - 1, yi + len);
        merge(xi + len, yi, k - 1, xi + len, yi + len - 1);
        merge(xi + len, yi + len, k - 1, gx, gy);
    }
}
int main()
{
    col[0][0] = 1;
    col[0][1] = 2;
    col[1][0] = 3;
    col[1][1] = 4;
    int k, x, y;
    cin >> k >> x >> y;
    merge(1, 1, k, x, y);
    return 0;
}