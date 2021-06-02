#include <iostream>
#include<algorithm>
using namespace std;

bool map[101][101];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m, k;



int dfs(int x, int y)
{
    int size =1;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

	if (!visited[nx][ny] && map[nx][ny]) size += dfs(nx, ny);
    }

    return size;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;


    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u>> v;
        map[u][v] = true;
    }

    int ret= 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] && !visited[i][j] )
                
                ret = max(dfs(i,j), ret);        
        }
    }
    cout << ret <<"\n";

    return 0;
}