//dfs stack or 재귀
#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int c[7]; // 방문체크
vector<int> a[8];//인덱스처리


void dfs(int x){
    if(c[x]) return; //방문 했다면 return
    c[x] = true; // 방문처리
    cout << x <<' ';
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        dfs(y);
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

    dfs(1);
}
