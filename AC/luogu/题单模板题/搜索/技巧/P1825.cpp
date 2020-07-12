#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
const int maxn = 305;
char f[maxn][maxn];
struct node
{
    int first, second;
    node(int x, int y) : first(x), second(y) {}
    bool operator==(const node &rhs) const
    {
        return rhs.first == first && rhs.second == second;
    }
};
struct MyhashFunc
{
    std::size_t operator()(const node &rhs) const
    {
        return std::hash<int>()(rhs.first * 1000 + rhs.second);
    }
};
vector<node> v[26];
int n, m;
queue<node> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int isvis[maxn][maxn];
int dis[maxn][maxn];
void cs(int &x, int &y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (x == i && y == j)
                continue;
            if (f[i][j] == f[x][y])
            {
                dis[i][j] = dis[x][y];
                x = i;
                y = j;
                return;
            }
        }
    }
}
int bfs()
{
    while (!q.empty())
    {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (f[x][y] <= 'Z' && f[x][y] >= 'A')
        {
            cs(x, y);
        }
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < n && nx >= 0 && ny < m && ny >= 0 && f[nx][ny] != '#')
            {
                //std::cout << "q1 " << nx << " " << ny << " " << f[nx][ny] << " " << endl;
                if (f[nx][ny] == '=')
                {
                    dis[nx][ny] = dis[x][y] + 1;
                    return dis[nx][ny];
                }
                if (!isvis[nx][ny])
                {
                    isvis[nx][ny] = 1;
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(node(nx, ny));
                }
            }
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &f[i][j]);
            if (f[i][j] <= 'Z' && f[i][j] >= 'A')
            {
                v[f[i][j] - 'A'].push_back(node(i, j));
            }
            else if (f[i][j] == '@')
            {
                q.push(node(i, j));
                isvis[i][j] = 1;
                dis[i][j] = 0;
            }
        }
    }

    int ans = bfs();
    std::cout << ans << endl;
}