#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 

int n;

int  w, h;

int dy[4] = {0,0,-1,1} ;
int dx[4] = {-1,1,0,0};

char map[101][101] ;
int isvisited[101][101] ;
void dfs(int y, int x) {
    isvisited[y][x] = 1;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i] ;
        if(ny < n || y <0) continue;
        dfs(ny,)
    }

}


int main(){
    cin >>n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(map[i][j] == '.'){
                dfs(i,j) ;
            }
        }
    }

}