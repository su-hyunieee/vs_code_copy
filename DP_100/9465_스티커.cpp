#include<iostream>
#include<algorithm>
using namespace std;

int st[2][1000001];
int dp[2][1000001];

int main(){

int t ;
int n;

cin >>t;


while (t-- > 0)
{
    cin >>n;

    for(int i=0; i<2; i++){
        for(int j=1; j<=n; j++){

            cin >>st[i][j];
        }

    }

    dp[0][0]= dp[1][0] =0;
    dp[0][1] =st[0][1];
    dp[1][1] = st[1][1];


    for(int i =2; i<=n ;i++){

        dp[0][i] = st[0][i] + max(dp[1][i-1],dp[1][i-2]);
        dp[1][i] = st[1][i] + max(dp[0][i-2],dp[0][i-1]);
    }




    cout << max(dp[0][n], dp[1][n])<<"\n";

}





}




