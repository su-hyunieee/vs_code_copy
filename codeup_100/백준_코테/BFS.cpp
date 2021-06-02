#include<iostream>
#include<queue>
#include<vector>
using namespace std;


//1 2 3 4 5 6 7
vector<int> a[8];
int c[7] ; // visit check

/*
시작점을 큐에다 넣고 방문처리 하고
큐가 빌 떄까지 . . 큐 맨 위를 x 에 저장하고 위에 팝
하고 x 출력
x와 인접한 애들이 방문 안 됐다면 큐에 푸시하고 방문 처리
*/

void bfs(int start){
queue<int> q;
q.push(start);
c[start] =true;

while(!q.empty()){
    int x = q.front();
    q.pop();
    cout << x << " ";

    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(!c[y]){
            q.push(y);
            c[y] = true;
        }
    }
}
}


int main(){

    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);     
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    bfs(1);


}