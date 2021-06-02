

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int n, m;
int map[8][8];
int temp_map[8][8];
int ret;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

/*

1. 연구소 입력을 받고
2. 원래 map에서 0이면 temp에서 1로 해주고 wall만드는 함수를 돌리고
    temp를0으로 돌려서 다 돌수있게 해줌
3. wall벽세우기는 재귀로 세번이니까
    cnt ==3 이되면 spread함수 호출하고 종류
    벽세우기
    temp lab ==0 이면 1로 바구ㅝ주고 wall+1해서 다시 호출 하고
    0으로 바꿔주는 ->백트랙킹
4. spread
    바이러스 퍼진후 상황 저장할 하나 더 map 만들어서
    임시거 저장하고
    2라면 큐에 넣고 fs 돌린다. 
    범위내에 있고 0이라면 2로 만든다
    그리고 새로운 맵에 0개수 체크 하고 비교해서 최대값
*/

void copy_map(int (*a)[8], int (*b)[8])
{

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            a[y][x] = b[y][x];
        }
    }
}

void virus()
{
    int spread_map[8][8];


    queue<pair<int, int > >q;
    copy_map(spread_map, temp_map);

    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            if (spread_map[y][x] == 2)
                q.push(make_pair(y, x));

    while (!q.empty())
    {
        int sy = q.front().first;
        int sx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = sy + dy[dir];
            int nx = sx + dx[dir];
           
            if (0 <= nx && nx < m && 0 <= ny && ny < n)
            {
                if (spread_map[ny][nx] == 0)
                {
                    spread_map[ny][nx] = 2;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
        }}


    int c = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (spread_map[y][x] == 0)
                c += 1;
        }
    }

    ret = max(ret, c);
}

void make_wall(int cnt)
{
    if (cnt == 3)
    {
        virus();
        return;
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (temp_map[y][x] == 0)
            {
                temp_map[y][x] = 1;
                make_wall(cnt + 1);
                temp_map[y][x] = 0;
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {

            cin >> map[y][x];
        }
    }

    //벽 세울 데 찾기
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 0)
            {
                copy_map(temp_map, map);
                temp_map[y][x] = 1;
                make_wall(1);
                temp_map[y][x] = 0;
            }
        }
    }

    cout << ret << endl;
}