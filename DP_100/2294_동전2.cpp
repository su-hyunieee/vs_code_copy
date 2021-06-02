#include<iostream>
#include<algorithm>
using namespace std;

//못하겟으니까 나중에 다시 풀어봐 .. ~ 
// 모르겠으면 코드 따라치기라도 해봐 .. ~

int main(){

int n,k;

int dp[100001];
int coin[101];

cin>> n>>k;

for(int i=1 ; i<=n; i++) cin >> coin[i];

for(int i=1 ;i<=k; i++) dp[i]= 100001;


dp[0]= 0;

for(int i=1; i<=n; i++){
    for(int j= coin[i]; j<=k; j++){
        dp[j]= min(dp[j], dp[j-coin[i]]+1);
    }
}

if(dp[k] == 100001) dp[k] = -1;


printf("%d", dp[k]);


}