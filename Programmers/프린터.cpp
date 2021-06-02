#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> prior, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    
    for(int i=0; i< prior.size(); i++){
        dq.push_back({i,prior[i]});
    }
    
    while(!dq.empty()){
        pair<int, int> temp = make_pair(dq.front().first, dq.front().second);
        
        bool flag = false;
        
        for(int i=0; i< dq.size(); i++){
            if(temp.second < dq[i].second){
                flag =true;
                dq.pop_front();
                dq.push_back(temp);
                break;
            }
            
        }
        
        if(flag == false){
            dq.pop_front();
            answer ++;
            //빼다가 원하는 위치다 싶으면 return
            if(temp.first ==location){
                return answer;
            }
        }
        
    }
  
    return answer;
}