#include<stdio.h>


int n,k,m;

//필요한거.. .뱀의 정보. . map
int map[101][101];
int cmd[10001];
int snake_y[10101], snake_x[10101];
int head_x, head_y, tail_index;


const int dy[]= {0,1,0,-1};
const int dx[]= {1,0,-1,0};

int main(){

//printf("*****START*******\n");

scanf("%d %d", &n, &k); // map크기랑 사과의개수

int y,x;
for(int i=0; i<k; i++){
    scanf("%d %d", &y,&x);
    map[y][x] = 1; // 사과 있음
}

int time;
char c;

scanf("%d", &m);

for(int i=0;i<m; i++){
    scanf("%d %c", &time, &c);
    cmd[time] = c;
}


//뱀 초기화
//1,1에 있고 tail길이는0
//시작이니까 기준은 머리
int dir =0;

time =0;
snake_y[time]=1,snake_x[time]=1, tail_index=0;
head_y =1, head_x=1;
map[head_y][head_x] =-1;


//뱀 움직인다.
while (1)
{
    ++time;

    head_y += dy[dir];
    head_x += dx[dir];

    //벽에 부딪히거나 자신과 만나서 끝날때
    if(head_y <1 || head_y>n ||head_x <1 || head_x>n || map[head_y][head_x]==-1){
        break;
    }
    
    //update
   snake_y[time] = head_y;
   snake_x[time] = head_x;

    //사과가 없으면 tail_index ++, tail위치에 0으로 뱀 없음 해줘
    if(map[head_y][head_x]==0){
        int tail_y = snake_y[tail_index];
        int tail_x = snake_x[tail_index];
        ++tail_index;
        map[tail_y][tail_x] =0; // 뱀없음
    }

    
    //뱀있음 대가리에는 맨날 있으니까.
    map[head_y][head_x] =-1;

    //오른쪽
    if(cmd[time]=='D'){

        dir =(dir + 1)%4;
    }

    //왼쪽
    if(cmd[time]== 'L'){
        dir =(dir + 3)%4;
    }
  
 
}

printf("%d\n", time);
return 0;
}














