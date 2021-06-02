#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int b_len, int weight, vector<int> truck) {
    int time =0;
    int sum =0;
    int idx =0;
    queue<int> q;
    
    while(1){
    
        //마지막 트럭이면 그냥 len만큼 더해버리기
        if(idx == truck.size() ){
            time += b_len ;
            break;
        }
        
        time ++;
        
        int tmp = truck[idx] ;
        
        //다리가 다 찼다
        if(q.size() == b_len){
            // 맨 앞에 있는거 다리 지남
            // 무게 빼주고 pop
            sum -= q.front();
            q.pop();
        }
        
        // 다리에 있는 트럭이랑 현재 트럭도 올라갈수 있다.
        if(sum + tmp <= weight){
            //현재 트럭도 다리위에 올리고 무게 증량
            q.push(tmp);
            sum += tmp;
            //다음 트럭으로 옮김
            idx++;
        }
        else{
            //현재 트럭이 다리위에 못 올라가면 0을 넣어서 지나가는중으로 만들기
            q.push(0) ;
        }
        
        
    }

    
    return time;
}