#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];
int w[10001];
int v[1001];


//knapsack algorithm
//가지고 나올수 있는 보석의 무게의 한계가 있을 때 보석 가치의 합 
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

 //i 번째 보석 j는 내가 들수있는 무게
    for(int i=1 ; i<=n; i++){
        for(int j=0; j<=k; j++)
        {
            //i 번째 보석을 챙기지 않음
            dp[i][j] = dp[i-1][j];

            if(j-w[i]>=0){
                //i 번째 보석을 챙김           i-1에서 지금 보석무게 빼고 거기에 지금가치 더하기
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            }



        }
    }


    cout <<dp[n][k];

}