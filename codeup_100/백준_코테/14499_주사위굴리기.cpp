#include <iostream>
#include <stdio.h>
using namespace std;

int n, m, k, sy, sx;

int map[20][20];
int dice[6];

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

//굴려~
void gool(int dir)
{

    int new_dice[6];

    switch (dir)
    {
    case 0:
        new_dice[0] = dice[0];
        new_dice[5] = dice[1];
        new_dice[2] = dice[2];
        new_dice[4] = dice[3];
        new_dice[1] = dice[4];
        new_dice[3] = dice[5];

        break;
    case 1:
        new_dice[0] = dice[0];
        new_dice[4] = dice[1];
        new_dice[2] = dice[2];
        new_dice[5] = dice[3];
        new_dice[3] = dice[4];
        new_dice[1] = dice[5];
        break;
    case 2:
        new_dice[3] = dice[0];
        new_dice[0] = dice[1];
        new_dice[1] = dice[2];
        new_dice[2] = dice[3];
        new_dice[4] = dice[4];
        new_dice[5] = dice[5];
        break;
    case 3:
        new_dice[1] = dice[0];
        new_dice[2] = dice[1];
        new_dice[3] = dice[2];
        new_dice[0] = dice[3];
        new_dice[4] = dice[4];
        new_dice[5] = dice[5];
        break;

    default:
        break;
    }

    // 주사위 복사
    for (int i = 0; i < 6; i++)
    {
        dice[i] = new_dice[i];
    }
}

int main()
{
    cin >> n >> m >> sy >> sx >> k;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {

            cin >> map[y][x];
        }
    }

    int dir;

    for (int i = 0; i < k; i++)
    {

        cin >> dir;

        --dir;
        int ny = sy + dy[dir];
        int nx = sx + dx[dir];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
        {
            continue;
        }

        gool(dir);

        if (map[ny][nx] == 0)
        {
            map[ny][nx] = dice[3];
        }
        else
        {
            dice[3] = map[ny][nx];
            map[ny][nx] = 0;
        }

        //상태복사
        sy = ny;
        sx = nx;

        cout << dice[1] << endl;
    }
}