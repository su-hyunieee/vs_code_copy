#include<iostream>
using namespace std;


//  범위가 c++ 안 돼서 string 저장 ??
// ㄲㅈ 안 해

int n;
long long dp[1000001] = {0,1};

int main(){

long long ret = 0;

cin >>n;

if(n ==0) ret = dp[0];
else{
for(int i =2 ;i<=n; i++){
dp[i] = (dp[i-1] +dp[i-2])%15000 ;
}
ret = dp[n];
}

cout << ret ;

}
