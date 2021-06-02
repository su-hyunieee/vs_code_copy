#include<iostream>
using namespace std;
//https://jaemin8852.tistory.com/161
//https://www.acmicpc.net/problem/10844
//큰수가 있으면  변수 선언해서 쓰기 ;; ㅅㅂ

int dp[1001][10];
int mod = 1000000000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,i,j;
    long long sum =0;

    //1-9
    for(i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    cin >>n;

    for(i=2; i<=n; i++){
        for(j = 0; j<=9; j++){
            if(j==0) dp[i][j] = dp[i-1][j+1]; //1에서만
            else if(j==9) dp[i][j] =dp[i-1][j-1]; //8에서만 
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }

    for(i =0; i<=9; i++) sum += dp[n][i];


    cout <<sum % mod <<endl;



}