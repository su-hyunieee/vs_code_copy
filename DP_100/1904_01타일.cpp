#include <iostream>
#include <algorithm>
using namespace std;

long dp[1000001];

int main()
{
    int n;

    cin >> n;

    dp[1] = dp[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] )%15746;
    }

    cout <<dp[n];


}
