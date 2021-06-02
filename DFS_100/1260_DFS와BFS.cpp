#include <iostream>
#include <algorithm>
#include<string.h>
#include <queue>
using namespace std;

//시작점을 넣고 . . . . .
//정점의 개수만큼 돌리는게 기본원리 시발롬아!


int n, m; // 정점 간선
int v;
int map[1001][1001];
int isvisited[1001];

void dfs(int start)
{

    cout << start << ' ';
    isvisited[start] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (isvisited[i] == 0 && map[start][i] == 1)
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    queue<int> q;

    //시작점을 넣고 시작점을 방문 한 다음에 
    //큐바 빌때까지  start 주고 팝 그리고 안들렀고1이면 다시 넣고 방문하고 
    q.push(start);

    isvisited[start] = 1;

    while (!q.empty())
    {
        start = q.front();
        cout << start << ' ';
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (isvisited[i] == 0 && map[start][i] == 1)
            {
                q.push(i);
                isvisited[i] = 1;
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;
    int a, b;

    for (int i = 0; i < m; i++)
    {

        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }

    dfs(v);

    cout << "\n";

    memset(isvisited, false, sizeof(isvisited));
    
    bfs(v);

    return 0;
}