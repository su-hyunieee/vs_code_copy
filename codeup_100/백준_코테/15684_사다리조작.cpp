#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
/*
chk함수 : 선이 있으면 true 없으면 false
*/


int n,m,h;
int map[34][34];

int ret  ;

bool chk(){

bool ret = true;

        
        // 
    for(int i=1; i<=n; i++){
        int start =i;
        //6번째에는 못그어서 0부터
        for(int j=0; j<=h ; j++){
            if(map[j][start]==1)  {++start;}
            else if( map[j][start-1]==1) {--start;}


        }

    if(start!=i) return ret = false;

    }


    return ret;
}



void dfs(int cnt, int y,int x){
     //최소값 보다 크면 이미 다 찾은거임
    if( cnt >= ret) return;
    
     // ret에 cnt 넣음
    if(chk()){
        ret = cnt;
        return;
    }   

    if( cnt == 3) return ;


    for(int i= y; i <=h; i++){
        for(int j=x; j<n; j++){
            //나한테 다리가 없고 옆에도 다 없으면
            if(map[i][j]==0 && map[i][j-1]==0 && map[i][j+1]==0){
                map[i][j] =1; //다리를 놓고
                dfs(cnt+1, i,j); //dfs 돌린다
                map[i][j] =0; //backtracking때문에 이렇게

            }
            
        }
    x =1; //첫번째 h부터 다시 놔야 되나꺼
    }
}



int main(){
int a,b;

//  세로선  가로선 놓을수있는위치의 개수
cin >> n >>m>> h ;


for(int i=0; i<m;i++){
    
    cin >> a>>b;
    map[a][b] = 1;

}

//걍 삼보다 큰걸로 일단
ret =4;

//cnt 1,1 시작위치
dfs(0,1,1);

if(ret ==4) {ret =-1;}

cout << ret <<endl;
}