
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m;
int ret;
int map[501][501];
bool chk[501][501];

/*
걍 못 풀음 시발
왜 하나만 안 되는데 ?
*/

int dy[] = {-1,1,0,0 };
int dx[] = { 0,0,-1,1};

int ey[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int ex[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};


void dfs(int y, int x, int sum, int len){

    if(len == 4){
        ret = max(ret, sum);
        return;
    }

    for(int dir=0; dir<4; dir++){

      //  ++dir;
        int ny = y + dy[dir];

        int nx = x + dx[dir];

       if(nx <0 || nx>=m || ny<0 ||ny>=n)continue;

        if (chk[ny][nx] == false)
        {
            chk[ny][nx] = true;
            dfs(ny, nx, sum + map[ny][nx], len + 1);
             chk[ny][nx] = false;
        }
    }
}

void chk_n(int y, int x)
{

    int base = map[y][x];
    int cnt = 0;
   int mini = 2147483647;
    
for(int y=0 ;y<4; y++){
    bool isOut =false;
    int sum_value =0;
    for(int x=0 ; x<4; x++){
        int ny = y + ey[y][x];
        int nx = x + ex[y][x];
    if(nx <0 || nx>=m || ny<0 ||ny>=n){
            isOut = true;
            break;
        }
        else{
            sum_value  += map[ny][nx];
        }
    }
    if(isOut == false){
        ret = max(ret, sum_value);
    }
}



}

int main(){

//cin >> n >>m ;
     scanf("%d %d", &n, &m);

     int result =0;


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &map[y][x]);
        }
    } 


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            chk[y][x] = true;
            dfs(y, x, map[y][x],1);
            chk[y][x] = false;
            chk_n(y,x);
        }
    }

cout <<ret <<endl;


}

