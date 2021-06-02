#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

//존나 어려운데 ?? 시발
//블락이 일일때 ? 생각 안 해줘도 되는게 신기;;

int n, m;
char map[1001][1001];
int isvisited[1001][1001][2];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

//1 cant 0 go
int bfs()
{ // y  x     block
    queue<pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(1, 1), 1));
    isvisited[1][1][1] = 1;

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;

        q.pop();

        if(y == n && x ==m) return isvisited[y][x][block];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny <= n && nx <= m && ny >= 1 && nx >= 1)
            {
                //벽이면서 아직 뚫은적이 없다면
                if(map[ny][nx]=='1' && block){
                    //전진해주고 개수 없어준다 
                    isvisited[ny][nx][block-1] = isvisited[y][x][block]+1;
                    q.push(make_pair(make_pair(ny,nx),block-1));
                }

                //길이 있고 들른적 없으면 최단경로 찾아서 가기
                if(map[ny][nx]=='0' && isvisited[ny][nx][block]==0){

                    isvisited[ny][nx][block] = isvisited[y][x][block] +1;
                    q.push(make_pair(make_pair(ny,nx), block));
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d" , &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", &map[i][1]);
    }

    cout << bfs() << '\n';
    
    return 0;
}