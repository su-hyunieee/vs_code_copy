#include<iostream>
#include <cstring>
#include<queue>
using namespace std;
//queue 기본은 내림차순
// greater 하면 오름차순
//https://rebas.kr/714

//아 존나 어렵다 시발롬

struct shark{
    
    int d,y,x;
    bool operator < (const shark &t) const {
           if (d == t.d) {
               if (y == t.y) return x > t.x;
               else return y > t.y;
           } else return d > t.d;
       }
};


int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};



int n, eat, ans, body = 2;
int map[21][21];
bool visited[21][21];

priority_queue<shark> q;


void bfs(){
  
    
    while (!q.empty()) {
        int d = q.top().d;
        int y = q.top().y;
        int x = q.top().x;
        q.pop();
        
        if(map[y][x]> 0 && map[y][x] < body){
         
            map[y][x] =0;
            eat ++;
            if(eat == body){
                body ++;
                eat =0;
            }
            ans += d;
            
            //다음 물고기를 먹기 위해 움직일 때,이미 갔던 곳일수도 있다 따라서 다 초기화 ?
            //먹은다음에 최단거리 변경 될수도 있으니까  초기화 다시 비에프에스 시작한다는 개녀ㅕㅕㅕㅁ .
            d= 0;
            memset(visited,false,sizeof(visited));
            while (!q.empty()) q.pop();

        }
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(nx <0 || nx>=n || ny<0 || ny>=n )continue;
            if(visited[ny][nx])continue;
            if(map[ny][nx] > 0 && map[ny][nx] > body) continue;
            
            q.push({d+1, ny,nx});
            visited[ny][nx] = true;
        }
    }
    
    
}


int main(){
    
    cin >>n;
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<n ;j++){
            cin >>map[i][j];
            
            if(map[i][j]==9){
                q.push({0,i,j});
                map[i][j] = 0;
            }
        }
    }
    body = 2;
    bfs();
    
    cout <<ans;
    
    return 0;
}
