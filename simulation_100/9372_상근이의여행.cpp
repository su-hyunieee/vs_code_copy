#include<iostream>
using namespace std;

//MST, 가선에 가중치가 존재하지 않고 모든 노드를 방문할수 있는 최소 엣지 방문횟수를 담는다
//모든 노드를 방문할수 있는 경로가 존재 -> 간선이 n-1인경우가 항상 최소

int main(){
    int t; 
    int n,m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>t;

    while (t--)
    {
        cin >> n >>m;
        for(int i=0; i<m; i++){
            int a , b;
            cin >>  a >>b;
        }
   
        cout << n-1 << '\n';
    }
    



}