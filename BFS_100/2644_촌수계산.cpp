#include <iostream>
#include <queue>
using namespace std;

//bfs가 더 어렵다 시발
//#똥먹기완승
int n, m;
int map[101][101];
int visited[101];
int res = -1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    int start, ed;
    cin >> n >> start >> ed >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }

    queue<int> q;

    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (map[now][i] == 1 && visited[i] == 0)
            {
                {
                    q.push(i);
                    visited[i] = visited[now] + 1;
                }
            }
        }
    }

    // end 에 도달했냐?      ㅇㅇ 촌수       아니 안들름
    cout << (visited[ed] ? visited[ed] : -1);
}