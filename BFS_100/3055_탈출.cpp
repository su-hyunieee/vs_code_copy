#include <iostream>
#include <queue>
using namespace std;


//bfs 2

int r, c;
char map[51][51]; 
int visited[51][51];//고슴토치
int water[51][51];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int sy, sx;
int ey, ex;

queue<pair<int, int> > w;

void water_bfs()
{

    while (!w.empty())
    {
        int y = w.front().first;
        int x = w.front().second;
        w.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < r && nx < c)
            {   
                if (water[ny][nx] == 0 && map[ny][nx] == '.')
                {
                    water[ny][nx] = water[y][x] + 1;
                    w.push(make_pair(ny, nx));
                }
            }
        }
    }
}

void bfs()
{
    queue<pair<int, int> > q;

    q.push(make_pair(sy, sx));
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < r && nx < c)
            {

                if (visited[ny][nx] == 0 && (map[ny][nx] == '.' || map[ny][nx] == 'D'))
                {

                    if (water[ny][nx] == 0)
                    {
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push(make_pair(ny, nx));
                    }
                    else
                    {
                        //이동하려는 칸이 다음날 물에 차오르지 않는 다면 ?
                        //고슴도치가 물보다 빠르게 움직인다.
                        if (water[ny][nx] > visited[y][x] + 1)
                        {
                            visited[ny][nx] = visited[y][x] + 1;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> map[i];
        for (int j = 0; j < c; j++)
        {

            if (map[i][j] == 'S')
            {
                sy = i;
                sx = j;
            }
            if (map[i][j] == '*')
            {
                w.push(make_pair(i, j));
            }

            if (map[i][j] == 'D')
            {
                ey = i;
                ex = j;
            }
        }
    }

    water_bfs();

    bfs();

    if (visited[ey][ex] != 0)
    {
        cout << visited[ey][ex];
    }
    else
    {
        cout << "KAKTUS";
    }
}