#include <string>
#include <vector>
#include <iostream>
using namespace std;


/*

기본적인 dfs 문제
전역으로 선언이 안 돼서 computers 랑 n을 끌고 와야 되는게 쩜 짜증 짜증 왕짜증이긴 함
*/
bool isvisited[201];
int answer = 0;

void dfs(int y, int n ,vector<vector<int>> computers){
    
    isvisited[y] = true;
    
    for(int i = 0; i< n ; i++){
        if(isvisited[i] == false && computers[y][i]){
            dfs(i,n , computers);
        }
    }
    

}

int solution(int n, vector<vector<int>> computers) {
    
    
    cout << computers[0][0] << computers[0][1] << computers[0][2] ;
    
    for(int i=0; i<n; i++){
        if(isvisited[i] == false){
            dfs(i,n, computers);
            answer++;
        }
    }
    
    return answer;
}