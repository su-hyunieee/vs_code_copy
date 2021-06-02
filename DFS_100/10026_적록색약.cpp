#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

// 단순무식 김*현같이 풀면 앙대~
// R == G이면. . . .이랑 memeset 햐줘야 하는거 고려 해야 된다. . 
//그다지 어려운 문제는. . 아닌듯. .

int n;
char map[101][101];
int isvisited[101][101] ;

int normal ;
int unnormal;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int i, int j){
    
    isvisited[i][j] = 1;

    for(int k=0; k<4; k++){
        int nx = j + dx[k];
        int ny = i + dy[k];
        
        if((map[i][j] == map[ny][nx]) && isvisited[ny][nx] == 0){
               if(nx <= n && ny <= n && nx> 0 && ny >0){
                dfs(ny,nx);
                }
        }
     
    }

}



int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL) ;



    scanf("%d" , &n) ;

    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            scanf("%1s", &map[i][j]);
        }
    }

    // 정상 
    for(int i = 1; i <=n ; i++){
        for(int j=1; j<=n ; j++){
            if(isvisited[i][j]==0){
                normal ++;
                dfs(i,j);
            }
        }
    }

    memset(isvisited, 0, sizeof(isvisited));

       for(int i = 1; i <=n ; i++){
        for(int j=1; j<=n ; j++){
         if(map[i][j] == 'R') map[i][j] = 'G' ;
             }
    }


    for(int i = 1; i <=n ; i++){
        for(int j=1; j<=n ; j++){
            if(isvisited[i][j]==0){
                unnormal ++;
                dfs(i,j);
            }
        }
    }


    cout <<normal << " " <<unnormal ;


}