#include <iostream>
#include<set>
#include <algorithm>
using namespace std;

/*
처음부터 끝까지 돌려보면서 비교해서 
뒤에 애보다 크기가 크고 길이가 1 긴지 비교하고 넣는데
*/

int main()
{

    int n;
    int Max = 0;

    

    int arr[1000001];
    int dp[1000001];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        { //더 작은 인덱스값이 현재 인덱스보다 더 큰가 ?
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                
            }
        }
        Max = max(dp[i], Max);
    }

    printf("%d\n", Max);

    

}
