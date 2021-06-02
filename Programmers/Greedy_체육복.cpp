#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+2, 1);
    
    for(auto i : lost) student[i]--;
    for(auto j : reserve) student[j]++;
    
    for(int i=1; i<=n; i++){
        if(student[i]==2 &&student[i-1]==0){
            student[i]--;
            student[i-1]++;
        }
        else if(student[i]==2 && student[i+1]==0){
            student[i]--;
            student[i+1] ++;
        }
    }
    for(int i=1; i<=n; i++){
        if(student[i]>=1){
            answer++;
        }
    }
    return answer;
}
