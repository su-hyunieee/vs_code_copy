#include <iostream>
using namespace std;
//ㅈㄴ 어이없네
///u,v가 1부터라서 for문을 1부터 돌려야 됨 시ㅏㅂㄹ

int n, m;
int res;
int map[1001][1001];
bool visited[1001];

void dfs(int p)
{

    visited[p] = true;

    for (int i = 1; i <= n; i++)
    {
        if (map[p][i] == 1 && visited[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    res = 0;
    cin >> n >> m;

    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            res++;
        dfs(i);
    }

    cout << res << "\n";
}