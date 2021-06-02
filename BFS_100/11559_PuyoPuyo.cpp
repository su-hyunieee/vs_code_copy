#include <iostream>
#include <cstring>
#include <string>
using namespace std;


/*
잘 생각해야 되는건. . 
반대로 배열을 돌려야 맨 아래부터 된다는거랑 
떨어뜨릴땐 열을 기준으로 떨어ㅈ뜨려야 되는거랑. .
bool 잘 쓰라는거 . . .
*/
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int n = 12;
int m = 6;

string map[12];
bool isvisited[12][6];
int idx = 1;

void dfs(int y, int x, int pre)
{
    isvisited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= n || ny < 0 || nx >= m || nx < 0)
            continue;
        if (!isvisited[ny][nx] && pre == map[ny][nx])
        {
            idx++;
            dfs(ny, nx, map[ny][nx]);
        }
    }
}

void remove()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isvisited[i][j])
            {
                map[i][j] = '.';
            }
        }
    }
}

void fall()
{
    for(int j =0; j<m; j++){
        while (1)
        {
            bool ok = false;

            for(int i= n-1; i>=1; i--){
                if(map[i][j]=='.' && map[i-1][j]!='.'){
                    map[i][j] = map[i-1][j];
                    map[i-1][j] = '.';
                    ok = true;
                }
            }
            if(!ok) break;
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    int ans = 0;
    while (1)
    {
        bool ok = false;

        // 왼쪽 아래
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                idx = 1;
                memset(isvisited, false, sizeof(isvisited));
                if (map[i][j] != '.')
                {
                    dfs(i, j, map[i][j]);
                    if (idx >= 4)
                    {
                        ok = true;
                        remove();
                    }
                }
            }
        }
        if (!ok)
            break;
        fall();
        ans++;
    }

    cout << ans;
}