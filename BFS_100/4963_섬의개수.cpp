#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int w, h;

        int cnt = 0;

int map[51][51];
bool visited[51][51];
int dx[8] = {0,0, -1,1,-1,1,-1,1};
int dy[8] = {-1,1,0,0,-1,-1,1,1};

void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 8; i++)
    {

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            continue;

        if (map[ny][nx] == 1 && visited[ny][nx] == false)
        {

            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {

                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {

            for (int j = 0; j < w; j++)
            {

                if (map[i][j] == 1 && visited[i][j] == false)
                {
                    // visited[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        memset(visited, false, sizeof(visited));
        cnt =0;
    }

    return 0;
}