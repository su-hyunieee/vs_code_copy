#include<iostream>
#include <limits.h>   
using namespace std;

long long dp[1500050];
long long n;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i =0 ; i< 1500000; i++)
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[i+2] = (dp[i] + dp[i+1]) % 1000000;
    }

    

    int ret = dp[n % 1500000];

    printf("%d", ret);



}