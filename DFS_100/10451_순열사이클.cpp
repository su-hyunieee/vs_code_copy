#include <iostream>
#include <string.h>
using namespace std;

//순열 같은 조합만 아니면 ?? 
// 그니까 안들러ㅓㅆ으면 중복 ㄴㄴ 인거임


int n, t;
int map[1001];
bool visited[1001];

void dfs(int num)
{

    visited[num] = true;

    if (visited[map[num]] == false)
    {
        dfs(map[num]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        memset(visited, false, sizeof(visited));
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> map[i];
        }
        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                dfs(i);
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}