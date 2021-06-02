#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001];
int p[10001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >>n;

    for(int i=1; i<=n; i++){
        cin >>p[i];
    }

    dp[1] = p[1] ;

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j]+p[j]);
        }
    }

    cout <<dp[n];

}