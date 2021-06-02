#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
문제를 생각하고  풀기
조금 깊게 생각하고 stl 좀 외우그라 마
*/

// 6 10 이라고 할떄
// 610 > 160 판단
bool cmp(string a, string b){
    return  a+b > b+a ;
}

string solution(vector<int> numbers) {
   ios::sync_with_stdio(NULL);
    
    string answer = "";
   vector<string> temp;
    for(auto num : numbers){
        temp.push_back(to_string(num));
    }
    sort(temp.begin(), temp.end(), cmp);
    
    //0이면 0으로 
    if(temp.at(0) == "0") return "0";
    
    for(auto num : temp){
        answer+=num;
    }

  
    return answer;

}