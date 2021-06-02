#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;




//구슬 정보
struct INFO{
    int ry, rx, by,bx ,count;

};

INFO start; //공의 시작 위치
char map[10][11];

int bfs(){

    //방향 정해주는 변수
    const int dy[]={-1,1,0,0};
    const int dx[]={0,0,-1,1};

    //chk
    int visited[10][10][10][10] ={0,};

    //start 초기화
    queue<INFO> q;    
    q.push(start);  //시작하면서 start 넣어준다
    visited[start.ry][start.rx][start.by][start.bx] =1;

    int ret =-1;
    while(!q.empty()){

        INFO cur = q.front();
        q.pop();

        //첫번째 실패 10번 넘게 카운트
        if(cur.count>10) break;

        // 최저값 찾는경우 빠져나오는 경우
        // red공이 O이고 blue가 O가 아닐때
        if(map[cur.ry][cur.rx]=='O' && map[cur.by][cur.bx]!='O'){
            ret = cur.count;
            break;
        }

        //공 움직이는 경우 외워 ㅅㅂ ;; 네방향으로
        //이럴때는 next 변수를 다로 만들어서 해
        for(int dir =0; dir<4; ++dir){

            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;


            while(1){

            //red move
            //#이 아니고 또.. O 아닐때
            if(map[next_ry][next_rx]!='#' && map[next_ry][next_rx]!='O'){
                next_ry +=dy[dir], next_rx+=dx[dir];
            }
            else{
                //벽이면 어쩔껀데 한칸 후퇴
                //O이면 끝이니까 이건 처리 ㄴㄴ
                if(map[next_ry][next_rx] =='#'){

                next_ry -=dy[dir], next_rx-=dx[dir];

                }
                break;
            }
            }

         while(1){
            //blue move
            //#이 아니고 또.. O 아닐때
            if(map[next_by][next_bx]!='#' && map[next_by][next_bx]!='O'){
                next_by +=dy[dir], next_bx+=dx[dir];
            }
            else{
                //벽이면 어쩔껀데 한칸 후퇴
                //O이면 끝이니까 이건 처리 ㄴㄴ
                if(map[next_by][next_bx]=='#'){

                next_by -=dy[dir], next_bx-=dx[dir];

                }
                break;
            }
         }
            //둘이 겹쳐

            if(next_ry== next_by && next_rx == next_bx){

                int red_dist = abs(next_ry - cur.ry)+ abs(next_rx-cur.rx);
                int blue_dist = abs(next_by - cur.by)+ abs(next_bx-cur.bx);
                
                //동시에 빠지는 경우는 -1이니까 처리 안해도 된다.
                if(map[next_ry][next_rx]!='O'){
                if(red_dist> blue_dist){

                        next_ry -=dy[dir], next_rx-=dx[dir];
                }else{

                      next_by -=dy[dir], next_bx-=dx[dir];

                }

                }
            }
        

            if(visited[next_ry][next_rx][next_by][next_bx]==0){
             
                visited[next_ry][next_rx][next_by][next_bx]=1;

                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;

                next.count = cur.count +1;

                q.push(next);
            }
       
        }
    }

    return ret;
}



int main(){

    int n,m;

    scanf("%d %d", &n,&m); // map크기 받기

    //전체를 받고
    for(int i =0; i<n; ++i){

        scanf("%s", map[i]);

    }

    //빨간공 파란공 찾기
    for(int y=0;y<n; ++y){
        for(int x=0; x<m; ++x){

            if(map[y][x] == 'R'){
                start.rx = x;
                start.ry =y;

            }

             if(map[y][x] == 'B'){
                start.bx = x;
                start.by =y;

            }
        }
    }

    start.count =0;

    int ret = bfs();
    printf("%d\n", ret);


    return 0 ;
}