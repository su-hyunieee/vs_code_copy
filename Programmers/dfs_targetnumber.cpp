#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int cnt){
    
    if( cnt == numbers.size() ){
        if(sum == target){
            answer ++;
            return ;
        }
    }  
    
    dfs(numbers, target, sum + numbers[cnt] , cnt +1 );
    dfs(numbers, target, sum - numbers[cnt] , cnt  +1 );
}

int solution(vector<int> numbers, int target) {
    int sum =0;
    
    dfs(numbers, target, sum, 0);
    
    return answer;
}