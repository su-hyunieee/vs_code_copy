#include<iostream>
#include<algorithm>
using namespace std;
//https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=220792326120&proxyReferer=https:%2F%2Fwww.google.com%2F

int dp[100001];
int main(){

    int n, i , j;

    cin >>n;

    for(i=1; i<=n; i++) dp[i] = i;

    for ( i = 2; i <= n; i++)
    {
       for(j= 2; j*j <= i; j++){
           dp[i] = min(dp[i], dp[i-j*j] +1);
       }
    }
    
    printf("%d", dp[n]);


}