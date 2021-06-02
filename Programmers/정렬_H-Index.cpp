#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

// int solution(vector<int> temp) {
//     //n개중 h번 이상 인용된 논문이 h편 이상이고 나머지가 h 번이하 잉용
//     //h의 최댓값이 이 과학자의 H-index
//     //1개씩 비교하면서 돌려야 되는
    
//     ios::sync_with_stdio(false);
//     int answer =0;
    
//     sort(temp.begin(), temp.end(), greater<int> ());
    
//     for(int i=0; i< temp.size(); i++){
    
//         if(temp[0] ==0) return answer;
        
//         if(temp[i] > i) answer++;
//         else break;
        
//     }
    
//     return answer;
// }

