#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
bool isvisited[101];
queue<int> q;

int n, m;
int cnt = -1; //1번컴퓨터 자신은 빼줘야 되니까 -1부터 새야 된다

void bfs(int start)
{

    isvisited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int ns = q.front();
        q.pop();

        
        cnt++;  
        //컴퓨터번호가1이라서 1부터 돌려줘야 된다 시발 아니면 틀림
        for (int i = 1; i <= n; i++)
        {
            if (isvisited[i] == false && map[ns][i] == 1)
            {
                isvisited[i] = true;
                q.push(i);
                

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

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }

    bfs(1);

    cout << cnt;
}