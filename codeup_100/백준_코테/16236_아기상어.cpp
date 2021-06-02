#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
 
 //위 왼쪽

struct SHARK{
    int y,x, time;


};

const int dy[]={0,0,1,-1};
const int dx[]={1,-1,0,0};
int n;
int map[20][20];
                //먹은개수
int shark_size, shark_eat;
SHARK shark;


int main(){
cin >>n;

for(int y=0; y<n; y++){
    for(int x=0; x< n; x++){

        cin >> map[y][x];
        if(map[y][x] ==9){
            shark.y = y, shark.x = x, shark.time=0;
            shark_size =2; shark_eat =0;
            map[y][x] =0 ; // 이게 중요


        }
    }
}

bool is_update = true;
SHARK candi;
while (is_update)
{
    is_update = false;
    bool visited[20][20] = { false,  };

    queue<SHARK> q;
    visited[shark.y][shark.x] = true;
    q.push(shark);

    
    while (!q.empty())
    {
        SHARK cur = q.front(); q.pop();

        candi.y = 20, candi.time =-1;
        //갱신 ㄴㄴ 가장 가까운 물고기는 이미 먹었다는 뜻
        if(candi.time != -1 && candi.time < cur.time){
            break;
        }

        if(map[cur.y][cur.x] < shark_size&& map[cur.y][cur.x]!=0){
            is_update = true;
            if(candi.y > cur.y || (candi.y == cur.y && candi.x> cur.x))
            {
                candi = cur;
            }
        
        }


        for(int dir=0; dir<4; dir++){
            SHARK next ;
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];
            next.time = cur.time +1;

        if(next.y < 0 || next.y >=n || next.x <0 || next.x>=n){
            continue;
        }
        if(visited[next.y][next.x]==false && shark_size >= map[next.y][next.x]){
            visited[next.y][next.x] = true;

            q.push(next);
        }
        
        }


        
        
    }
    
}


if(is_update){
   
   shark = candi;
    ++shark_eat ;
    if(shark_eat == shark_size){
        ++shark_size;
        shark_eat = 0;
    }

    map[shark.y][shark.x] =0;
}

cout << shark.time<<endl;
return 0;
}