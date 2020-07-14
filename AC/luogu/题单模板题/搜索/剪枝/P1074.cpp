#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int sco[10][10] = { //预处理每个格子分数
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
    {0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
    {0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
    {0, 6, 7, 8, 9, 10, 9, 8, 7, 6},
    {0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
    {0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
    {0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6}};
int f[10][10], row[10][10], col[10][10], block[10][10];
//f原图，row第i行第j的个数是否存在，col第i列第j个数是否存在，block第i个九宫格第j个数是否存在
int ans = -1;                     //输出答案
int cnt;                          //一共有多少个0
int cntr[10], cntc[10], cntb[10]; //第i行0的个数，第i列0的个数，第i个九宫格0的个数

struct Node //原图中0的点
{
    int x, y, val; //行位置，列位置，不确定度：所在行的0+所在列的0+所在九宫格的0
    bool operator<(const Node &rhs) const
    {
        return val < rhs.val;
    }
} s[100];                       //为0的点的集合
inline int belong(int x, int y) //找到属于哪个九宫格 编号1~9
{
    int tmp = 0;
    int a = (x - 1) / 3 + 1;
    int b = (y - 1) / 3 + 1;
    return (a - 1) * 3 + b;
}
inline void cal() //计算此时的得分
{
    int tmp = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            tmp += f[i][j] * sco[i][j];
        }
    }
    ans = max(ans, tmp);
}
void dfs(int now) //now表示搜索到了第now个点
{
    int x = s[now].x;
    int y = s[now].y;
    if (now == cnt)
    {
        cal();
    }
    int b = belong(x, y); //在哪一个九宫格
    for (int i = 1; i <= 9; i++)
    {
        //  cout << row[x][i] << col[y][i] << block[b][i] << f[x][y] << endl;
        if (!row[x][i] && !col[y][i] && !block[b][i])
        { //第x行是否有数字i   第y列是否有数字i 。。。 原图中是否这个位置还没有填
            f[x][y] = i, row[x][i] = 1, col[y][i] = 1, block[b][i] = 1;
            dfs(now + 1);
            f[x][y] = 0, row[x][i] = 0, col[y][i] = 0, block[b][i] = 0;
        }
    }
}
int main()
{

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> f[i][j];
            if (f[i][j])
            { //标记第i行这个数字已存在。。。
                row[i][f[i][j]] = 1, col[j][f[i][j]] = 1, block[belong(i, j)][f[i][j]] = 1;
            }
            else
            {
                cntr[i]++, cnt++;                   //统计行和列0的个数
                s[cnt - 1].x = i, s[cnt - 1].y = j; //把0的位置加入点集合s中
            }
        }
    }
    //编号0～cnt-1  计算每一个待填入数字位置的不确定度
    for (int i = 0; i < cnt; i++)
    {
        //s[i].val = cntr[s[i].x] + cntc[s[i].y] + cntb[belong(s[i].x, s[i].y)];
        s[i].val = cntr[s[i].x];
        //s[i].val = cntc[s[i].y];
    }
    stable_sort(s, s + cnt); //对点按不确定度排序
    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << s[i].x << " " << s[i].y << " " << s[i].val << endl;
    // }
    dfs(0);
    cout << ans << endl;
    return 0;
}