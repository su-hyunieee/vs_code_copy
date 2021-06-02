#include<iostream>
using namespace std;

//https://huiung.tistory.com/65


int n;
int map[101][101] ;
int isvisited[101][101];


void dfs(int y, int x)
{
    isvisited[y][x] = 1;

    for(int i =0; i<n ;i++){

            //안들렀고 x로 가는길이 있다
            //i->j->k
            if(isvisited[y][i] ==0 && map[x][i] ==1){
                dfs(y,i);
            }   
        
    }


}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin >>n;

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j =0; j<n ;j++){
            if(map[i][j] == 1) {
                dfs(i, j);
            }
        }
    }


    for(int i =0; i<n ;i++){
        for(int j=0; j<n ;j++)
            cout << isvisited[i][j] <<' ' ;
            cout << '\n' ;
        
    }    
    

}