#include <iostream>
using namespace std;
#define mod 10007

//계단이랑 비슷

int dp[1001][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, j, k;
    int sum = 0;

    cin >> n;

    //0-9
    for (i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (k = j; k <= 9; k++)
            {   dp[i][k] += dp[i - 1][j];
                dp[i][k] %= mod;
            }
        }
    }

    for (i = 0; i <= 9; i++)
        sum += dp[n][i];

    cout << sum % mod;
}