#include <iostream>
#include<string.h>
using namespace std;

int map[51][51];
int visited[51][51];
int t, n, m, k;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        //범위 탈출
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if (map[ny][nx] == 1 && !visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin >> t;

    for(int i=0; i<t; i++)
    {
        int ans = 0;
        
        memset(map,0 ,sizeof(map));
        memset(visited,0, sizeof(visited));

        cin >> m >> n >> k;
        int x, y;
        
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            map[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j); // 1이고 지렁이가 안갔으면 가서 들르고
                    ans++; //번들 추가 
                } 
            }
        }

        cout << ans <<"\n";
    }

    return 0;
}