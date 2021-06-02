#include <vector>
#include <algorithm>
#include<set>
#include<math.h>
#include <iostream>
using namespace std;


bool isPrime(int n){
    if(n <2) return false;
    
    for(int  i=2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}


int solution(vector<int> nums) {
    int answer = 0;
    set<int> s;
    vector<int> v;
    int cnt = 0;
    
    for(int i=0; i< nums.size(); i++){
        for(int j = i+1; j <nums.size() ; j++){
            for(int k = j +1; k < nums.size() ;k++){
                answer = nums[i] + nums[j] + nums[k];
                
                v.push_back(answer) ;
                
            }
        }
    }
    
    for(int i=0; i< v.size() ;i++){
        if(isPrime(v[i])){
             cnt ++;
        }    
        
    }
    return cnt;
    }