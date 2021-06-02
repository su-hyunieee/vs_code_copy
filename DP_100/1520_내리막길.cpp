#include<iostream>
using namespace std; 

/*
공부 다시 하고 풀기 . .이거 에바 어려움 
https://sihyungyou.github.io/baekjoon-1520/
*/

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int map[501][501];
int dp[501][501] ;

int dfs(int y, int x){


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>> n>> m;
    int y,x;

    for( y=0; y<=m; y++){
        for( x =0; x<=n; x++){
            dp[y][x] = -1;
            map[y][x] = 10001;
        }
    }

    for(y =1; y<=m;y++){
        for(x =1; x<=n; x++){
            cin >> map[y][x];
        }
    }


}