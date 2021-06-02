#include<iostream>
#include<algorithm>
using namespace std;


int t, n;
int dp[1000001] ;
int main() {

    cin >> t;

    dp[1] =1;
    dp[2] =2;
    dp[3] =4;

    while (t--)
    {
        cin >> n;
    
        for(int i =4; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[n] <<"\n"
        ;


    }
    

}