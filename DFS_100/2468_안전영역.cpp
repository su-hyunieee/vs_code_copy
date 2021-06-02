#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
// 실패 다시
// 1- 100까지 ?? 약간 디피같이 모든 경우 다 대보는. .근데
// 100이니까 그냥 ㅎ돌려도 시간은 ㄱㅊ 
//. . . . . . 어 . . . .민 맥스값 해주는게 전나 먼지 몰라서 인터넷 찾아봄
// 시발롬아

int n;
int map[101][101];
bool isvisited[101][101] = {
    false,
};

int max_val = 0;
int min_val = 101;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int height)
{
    isvisited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n)
        {  
               if (map[nx][ny] > height && !isvisited[nx][ny])
            {
                isvisited[nx][ny] = true;
                dfs(nx, ny, height);
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int result = 1; // 비가 안 오는 경우 전체가 한 덩어리

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            min_val = min(min_val, map[i][j]);
            max_val = max(max_val, map[i][j]);
        }
    }

    for (int i = min_val; i < max_val; i++)
    {
        int cnt = 0;

        memset(isvisited, false, sizeof(isvisited));

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (map[j][k] > i && !isvisited[j][k])
                {
                    cnt++;
                    dfs(j, k, i);
                }
            }
        }
        result = max(result, cnt);
    }

    cout << result;

    return 0;
}