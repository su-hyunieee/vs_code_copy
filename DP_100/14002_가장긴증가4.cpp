#include <iostream>
#include <vector>
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

    int arr[1001];
    int dp[1001];
    vector<int> v[1010];
    vector<int> A;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        v[i].push_back(arr[i]);
        for (int j = 0; j < i; j++)
        { //더 작은 인덱스값이 현재 인덱스보다 더 큰가 ?
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                v[i].clear();
                v[i] = v[j];
                v[i].push_back(arr[i]);
            }
        }

        Max = max(dp[i], Max);
        
        if (A.size() < v[i].size())
        {
            A = v[i];
        }
    }

    printf("%d\n", Max);

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
}
