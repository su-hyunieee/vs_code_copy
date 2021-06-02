#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;
int map[301][301];
            //오 아 왼 위
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void rotate(int box)
{
    for (int i = 0; i < box; i++)
    {
        int startVal = map[i][i];
        int y = i;
        int x = i;

        int k = 0;

        while (k < 4)
        {

            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny == i && nx == i) //원래 자리로 돌아오기
                break;
            if (i <= ny && ny < n - i && i <= nx && nx < m - i)
            {   // 반시계 방향으로 옮기기
                map[y][x] = map[ny][nx];
                y = ny;
                x = nx;
            }
            else
            {
                k++; //배열 범위에서 벗어났으니까 다른 라인 옮기기
            }
        }
        map[i + 1][i] = startVal; //빼둔거 넣기
    }
}

int main()
{

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int cnt = min(n, m)/2;

    for (int i = 0; i < r; i++)
    {
        rotate(cnt);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}