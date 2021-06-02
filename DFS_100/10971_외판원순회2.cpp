#include <iostream>
#include <algorithm>
using namespace std;

/*
모든 시작점에서 갈수있는 나라를 거쳐 다시 원래로 돌아옴 -> 모든 경우의 수 해야 되니까 빽트랙킹
 ii =0 갈수 없음
*/

int n;
int w[11][11];
bool isvisited[11];
int st;
int ans = 987654321;

void dfs(int y, int sum, int cnt)
{

    if (cnt == n -1 )
    {   //마지막에 들른 나라에서 다시 출발점 st로 돌아올수 있다면 
        if (w[y][st] != 0)
        {
            ans = min(ans, sum + w[y][st]);
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (w[y][i] != 0 && isvisited[i] == false)
        {
            isvisited[i] = true;
            dfs(i, sum + w[y][i], cnt + 1);
            isvisited[i] = false;
        }
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
            cin >> w[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        st = i;
        isvisited[i] = true;
        dfs(i, 0, 0);
        isvisited[i] = false;
    }

    cout << ans ;
}