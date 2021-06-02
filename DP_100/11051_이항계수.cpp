#include <iostream>
using namespace std;

int dp[1001][1001];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n>> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j | j == 0)
            {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
        }
    }

    cout << dp[n][k];
}