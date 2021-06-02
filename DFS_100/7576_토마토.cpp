#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//가 ㅅㅔ
int m, n;
int map[1001][1001];
int isvisited[1001][1001];

queue<pair<int, int> > q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            isvisited[i][j] = -1;

            if (map[i][j] == 1)
            {
                q.push(make_pair(i, j));
                isvisited[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || ny <= 0 || nx > n || ny > m)
                continue;
            if (map[nx][ny] == 0 && isvisited[nx][ny] == -1)
            {
                isvisited[nx][ny] = isvisited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }


    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result = max(result, isvisited[i][j]);
        }
    }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (map[i][j] == 0 && isvisited[i][j] == -1)

                    result = -1;
            }
        }

        cout << result;

    
    
    }