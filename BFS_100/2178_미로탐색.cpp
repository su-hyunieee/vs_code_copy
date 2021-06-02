#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[101][101];
int isvisited[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int y, int x)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    isvisited[y][x] = 1;


    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i =0 ;i< 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //맵 범위안에가 은근좆같네 . .. .
            if(nx >= 0  && ny >= 0 && nx < m && ny < n) {
                if(map[ny][nx]=='1' && isvisited[ny][nx] == 0){
                    q.push(make_pair(ny, nx));
                    isvisited[ny][nx] = isvisited[y][x] +1;
                }
            }

        }
      
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) 
     {cin >> map[i];
     }


    //1, 1 이니까 아래는 마이너스 일 해줘야댐 
    bfs(0, 0);

    cout << isvisited[n-1][m-1];

    return 0;
}