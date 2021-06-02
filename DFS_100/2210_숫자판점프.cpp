#include<iostream>
#include<set>
using namespace std;

//sum*10 + map[i][j] 헤줘야지
//1->2로 갈때 1*10 +2 = 12 이렇게
//12*10 + 2 해야 122이런식으로

int n= 5;
int map[5][5];
set<int> s; //중복방지 set

int dy[]= {-1,1,0,0};
int dx[] = {0,0,-1,1};

void dfs(int y, int x, int sum, int len){
  
    if(len == 6){
        s.insert(sum);
        return ;
    }

    for(int i=0;i <4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= n || ny < 0 || nx >= n || nx<0){
           continue;
        }
         dfs(ny,nx, sum*10 + map[ny][nx] , len+1);
     
    }


}

int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            cin >>map[i][j];
        }
    }



    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            dfs(i,j, map[i][j], 1);
        }
    }

    cout <<s.size() ;

}