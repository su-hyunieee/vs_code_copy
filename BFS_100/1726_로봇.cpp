#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
 이동명령을 내리고 방향 전환을 내려야 한다  . . . . . . .
 동서남북. . . . 그거 주는거 너무 어려움. . . . .ㅅㅂ
 */

struct robot{
    int y, x, dir;
};

//오른쪽으로 회전하기 위해서 +2
//왼쪽로 회전  +3
int dy[] = {0,0,0,1,-1};
int dx[] = {0,1,-1,0 ,0};


int n, m, ans;
int map[101][101];
int dist[101][101][5];


queue<robot> q;

int sx, sy,sd, ex ,ey,ed;

void bfs(){
    
    queue<robot> q;
    q.push({sy,sx,sd});
    
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int dir = q.front().dir;
        q.pop();
        if(x == ex && y == ey && dir == ed) {
            cout << dist[y][x][dir];
            return;
        }
        
        
        for(int i=1; i<=3 ; i++){
            int ny = y + i*dy[dir];
            int nx = x + i*dx[dir];
            
            if(nx < 1 || nx > n || ny< 1|| ny> m) break;
            if(map[ny][nx] ==1) break;
            if(dist[ny][nx][dir]) continue;
            q.push({ny,nx,dir});
            dist[ny][nx][dir] = dist[y][x][dir] +1;
            
        }
        
        for(int i=1; i<=4; i++){
            if(i == dir ) continue;
            //180 회전
            int k = (i+ dir)%4 == 3? 2:1;
            if(dist[y][x][i]) continue;
            q.push({y,x,i});
            dist[y][x][i] = dist[y][x][dir] + k;
            
        }
    }

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin >>m >>n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n;j++){
            cin >> map[i][j];
        }
    }
    
    cin >> sy >> sx >> sd;
    cin >> ey >> ex >> ed;

 
    bfs();
  

    return 0;

}
