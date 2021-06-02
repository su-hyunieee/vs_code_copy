#include <iostream>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    


    int n;
    int Max = 0;

    int arr[1001];
    int dp[1001];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        { //더 작은 인덱스값이 현재 인덱스보다 더 큰가 ? + 현재 비교값이 이전번째까지의 합 + 자신이 값보다 작은가? 크면 다시 세야 하니까
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
        if (Max < dp[i])
            Max = dp[i];
    }

    printf("%d\n", Max);
}
