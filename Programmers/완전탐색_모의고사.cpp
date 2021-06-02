#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int > answer;

        //벡터새끼 쓰기 죤ㄴ ㅏ어렵다 시발 .
        vector<vector<int>> supo{ {1,2,3,4,5}, {2, 1, 2, 3, 2, 4, 2, 5},{3, 3, 1, 1, 2, 2, 4, 4, 5, 5} } ;

        vector<int> cnt ={0,0,0} ;

        for(int i=0; i< answers.size(); i++){
            // i 만큼만 돌라고
            if(answers[i] == supo[0][i % supo[0].size()]) cnt[0] ++;
            if(answers[i] == supo[1][i % supo[1].size() ]) cnt[1] ++;
            if(answers[i] == supo[2][i % supo[2].size() ]) cnt[2] ++;
        }
     
        int ans = *max_element(cnt.begin(), cnt.end());

        for(int i=0; i<3; i++){
            if(cnt[i]== ans) answer.push_back(i+1) ;
        }

        return answer;
    
   
}