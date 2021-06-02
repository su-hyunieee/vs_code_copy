#include <iostream>
using namespace std;

int dp[45];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    for (int i = 2; i <= 45; i++)
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cin >> n;

    printf("%d\n", dp[n]);
}