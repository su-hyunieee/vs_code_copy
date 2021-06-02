#include <iostream>
#include <algorithm>
using namespace std;

int t[15000010];
int p[15000010];
int dp[15000010];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--)
    {

        if (i + t[i] > n + 1)
        {
            dp[i] = dp[i + 1];
        }
        else
        {

            dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
        }
    }
    cout << dp[1];
}