#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int map[101][101];

void floyd(){


    for(int k=1;k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){

                if(i==j) continue;
                else if(map[i][k] && map[k][j]){ // 가는 길이 있다
                    if(map[i][j]==0) map[i][j] = map[i][k] + map[k][j]; // i,j모를때 k로 업데이트
                    else map[i][j] = min(map[i][j], map[i][k]+ map[k][j]);//알면 작은걸로
                }
            }
        }
    }


}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>n >>m;
    for(int i=0; i<m; i++){
        int y,x;
        cin >> y>> x;
        map[y][x] = 1;
        map[x][y] =1;
    }

    floyd();

    int ret = 987654321;
    int per;

    for(int i=1 ;i<=n; i++){
        int sum=0;
        for(int j=1; j<=n; j++) sum += map[i][j];
        if(ret > sum){ // 동등해도 인덱스가 적은 사람 출력해야 돼서
            //최소값
            ret = sum;
            per = i;
        }
    }


cout <<per << '\n' ;




return 0;


}