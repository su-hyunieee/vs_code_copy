#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001][3];
int gp[10001];

//너무 어려워 개 시발롬아
//0 -> 안마심 1->1번연속 2->2번연속

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ret;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> gp[i];
    }

    for (int i = 1; i <= n; i++)
    {
       dp[i][0] = max(dp[i-1][0], dp[i-1][1]); // 이번에 안먹은거면 저번에서 먹은것 중 max
       dp[i][0] = max(dp[i][0], dp[i-1][2]); 

       dp[i][1] = dp[i-1][0] + gp[i]; //안마신거랑 이번꺼
       dp[i][2] = dp[i-1][1]+ gp[i]; // 1번 + 2 번꺼

    }
    
    //셋이 비교 
    ret = max(dp[n][0], dp[n][1]);
    ret = max(ret, dp[n][2]);

    cout <<ret ;
}