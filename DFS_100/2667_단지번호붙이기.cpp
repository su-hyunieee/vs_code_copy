#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

//dfs
//와우 .. 핵심. .%1d..였음을. .  한글짜씩 12341234를 1 2 3 4 이렇게 받아주는거였음. .이게 문제였던 것임 .. ㅅㅂ ;; 이게 뭐묘
//개 시발 그리고 씬으로 받으면 띄어쓰기 그거 때매 안 됨 .. 시발..

//for 문 1부터 돌려야 되는건. . . 단지번호를 1부터 붙이니까 그런거임. . 

int map[26][26];
int checked[26][26] = {};
int ans[26 * 26] = {};
int n;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


void dfs(int i, int j, int cnt)
{
    checked[i][j] = cnt;

    for(int k = 0; k < 4; k++){
        int x = i+dx[k];
        int y = j+dy[k];

        // x: 1~7, y: 1~7 범위안에 있을 때만 탐색 진행
        if(x >= 1 && x <= n && y >= 1 && y <= n){
            if(map[x][y] == 1 && checked[x][y] == 0)
                dfs(x, y, cnt);
        }   
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1 && checked[i][j] == 0)
            {
                dfs(i, j, ++cnt);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1)
            {
                ans[checked[i][j]] += 1;
            }
        }
    }

    sort(ans + 1, ans + cnt + 1);

    cout << cnt << "\n";

   
    for (int i = 1; i <= cnt; i++)
    {
        cout << ans[i] << "\n";
    }
}
