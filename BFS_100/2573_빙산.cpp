#include <iostream>
#include <string.h>
using namespace std;

//bfs로 바꿨는데 왜 안되는지 ㄹㅇㄹㅇㄹㅇㄹㅇ 모르겠음 ; ;ㅅㅂ
int n, m;
int map[301][301];
bool isvisited[301][301];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int year;

void dfs(int y, int x)
{

    isvisited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || ny >= n || nx >= m)
            continue;
        if (map[ny][nx] > 0 && isvisited[ny][nx] == false)
        {
            dfs(ny, nx);
        }
    }
}

void melt()
{

    int copy_map[301][301] = {0};

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            copy_map[y][x] = map[y][x];
        }
    }

    //바다로 인식하면 안 돼서 템프 쓰고 직접 빼주는건 맵에다가
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            int count = 0;
            if (copy_map[y][x] > 0)
            {

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (copy_map[ny][nx] == 0)
                        count++;
                }
                map[y][x] -= count;

                if (map[y][x] < 0)
                    map[y][x] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    while (1)
    {
        int flag = 0;
        int land = 0;
        memset(isvisited, false, sizeof(isvisited));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] != 0 && isvisited[i][j] == false)
                {
                    land++;
                    if (land == 2)
                    {
                        flag = 1;
                        break;
                    }
                    dfs(i, j);
                }
            }
        }

        if (flag == 1)
        {
            cout << year;
            break;
        }
        else if (land == 0)
        {
            cout << '0';
            break;
        }

        melt();

        year++;
    }

    return 0;
}