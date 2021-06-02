#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c;
char map[21][21];
int alphabet[26] = {0};
int ret = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int y, int x, int cnt)
{
    
        ret = max(cnt, ret);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < r && nx >= 0 && nx < c && alphabet[map[ny][nx] - 'A'] == 0)
        {
            alphabet[map[ny][nx] - 'A'] = 1;
            dfs(ny, nx, cnt + 1);
            alphabet[map[ny][nx] - 'A'] = 0;// 경로갱신을 위해
        } 
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    //배열에 알파벳 저장하기 
    alphabet[map[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << ret;
}