#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
int map[50][50];

//북동남서 근데 얜 한 번 돌면 왼쪽으로 돌아 index 3 증가
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

struct Robot
{

    int y;
    int x;
    int dir;
};
Robot robot;

queue<Robot> r;

int main()
{

    scanf("%d %d", &n, &m);

    cin >> robot.y >> robot.x >> robot.dir;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {

            cin >> map[y][x];
        }
    }

    queue<Robot> q;
    int ret = 0;

    //로봇 투입
    q.push(robot);
    //청소 기릿
    while (!q.empty())
    {
        Robot cur = q.front();
        q.pop();
        
        //청소 x -> 청소 ㅇ
        if (map[cur.y][cur.x] == 0)
        {
            map[cur.y][cur.x] = 2;
            ret++;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            Robot next;
            //네방향으로 도는데 왼쪽으로 돌아서 인덱스 +3 인데 -dir 해도 댐
            next.dir = (cur.dir + 3- dir) % 4;

            next.y = cur.y + dy[next.dir];
            next.x = cur.x + dx[next.dir];

            //조건 안맞거나 청소할 필요가 없으면 넘어가
            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m ||
                map[next.y][next.x] != 0)
            {
                continue;
            }

            //넣고 dfs 돌리는데 로봇 하나만 있어야 돼서 break 건다
            q.push(next);
            break;
        }

        //네방향 다 청소 돼있음 next에 들어온게 ㄴㄴ 함
        if (q.empty())
        {
            Robot next;
            //방향은 안바꾸고
            next.dir = cur.dir;
            //후진 빠꾸는 인덱스 +2
            next.y = cur.y + dy[(next.dir + 2 )% 4];
            next.x = cur.x + dx[(next.dir + 2 )% 4];

            //벽이거나 후진도 안 되면 꺼짐
            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m ||
                map[next.y][next.x] == 1)
            {
                break;
            }
            //아님 넥스트 넣고 실행
            q.push(next);
        }

    }

    cout << ret << endl;
    return 0;
}