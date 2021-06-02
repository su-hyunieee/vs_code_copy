#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

// 최 댓값 구할 대는 비교 할 최솟값이 필요해 .
// 진짜 못해먹겠다. .
int n;

int sum = -10001;

int main()
{
    int dp[MAX];
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        sum = max(dp[i], sum);
    }


    cout << sum;
}