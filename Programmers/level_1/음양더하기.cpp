#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> abs, vector<bool> sign) {
    int answer = 0;




    for(int i=0; i< abs.size(); i++){
        if(sign[i] == true){
            answer += abs[i] ;
        }
        if(sign[i] == false)
        {
            answer -= abs[i] ;
        }
    }



    return answer;
}