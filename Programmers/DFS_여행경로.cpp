#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://eunchanee.tistory.com/93

bool isvisited[10001];
vector<string> answer;
int max_cnt = 0;

void dfs(string cur,vector<vector<string>> tickets, vector<string> tmp, int cnt){
    
    tmp.push_back(cur);
   // cout << "start" << tmp.begin();
    if(max_cnt  < cnt) {
        max_cnt = cnt ;
        answer = tmp;
    }
    
    for(int i=0; i< tickets.size(); i++){
        if(tickets[i][0] == cur && isvisited[i] == false){
            isvisited[i] = true;
            dfs(tickets[i][1], tickets,tmp, cnt +1  );
            isvisited[i] = false;
            
        }
    }
  //  cout << "why" << tmp.begin();
    // 끝까지 못갔으면 뺀다 ?
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> tmp;
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, tmp, 0);
    
    
    return answer;
}