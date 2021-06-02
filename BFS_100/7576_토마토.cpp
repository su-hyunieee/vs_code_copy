#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int> > q;

void bfs()
{

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
           
            if (map[ny][nx] == 0)
            {
                map[ny][nx] = map[y][x] + 1;

                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();

    int Max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }

            Max = max(Max, map[i][j]);
        }
    }

    cout << Max -1;

    return 0;
}