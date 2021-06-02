#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

//어려운 문제 시발롬

int n;
int map[101][101];
bool isvisited[101][101];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x, int cnt)
{

    isvisited[y][x] = true;
    map[y][x] = cnt;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny < n && nx < n)
        {
            if (map[ny][nx] && isvisited[ny][nx] == false)
            {

                dfs(ny, nx, cnt);
            }
        }
    }
}

int bfs(int sum)
{

    queue<pair<int, int> > q;

    //해당 섬의 좌표를 다 큐에 넣기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == sum)
            {
                isvisited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    int result = 0;

    while (!q.empty())
    {
        int cur = q.size();
        //현재 큐에 있는 칸으로부터 한칸씩
        for (int i = 0; i < cur; i++)
        {

            int y = q.front().first;
            int x = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny >= 0 && nx >= 0 && ny < n && nx < n)
                {
                    //다른섬에 도착했을 경우 섬인데 다른섬이다
                    if (map[ny][nx] && map[ny][nx] != sum)
                        return result;
                    //바다이면서 가본적이 없는경우 
                    else if (map[ny][nx] == 0 && !isvisited[ny][nx])
                    {
                        isvisited[ny][nx] = true;
                        q.push(make_pair(ny, nx));//방문하고 큐에 넣는다
                    }
                }
            }
        
            cout <<result <<'\n';
        }
        cout <<" djswp dhsn" <<result <<'\n';
        result++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] && isvisited[i][j] == false)
            {
                dfs(i, j, cnt++);
            }
        }
    }

    int ret = 987654321;

    for (int i = 1; i < cnt; i++)
    {
        memset(isvisited, false, sizeof(isvisited));
        ret = min(ret, bfs(i));
    }

    cout << ret << '\n';
 
    return 0;
}