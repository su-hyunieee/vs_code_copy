#include <iostream>
#include <string>
using namespace std;
//https://sooooooyn.tistory.com/12
//먼지 하나도 모르겠어 .. ..ㅅㅂ..

string S, A[101];
int N;

bool dp[101];


int main()
{

    cin >> S >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    dp[S.length()] = 1;
    
    for(int i = S.length() -1; i>=0; i--){
        for(int j=0; j<=N; j++){
            if(S.find(A[j],i) ==i && dp[i + A[j].length() ]==1){
                dp[i] =1;
                break;
            }
            else{
                dp[i] =0;
            }
        }
    }
    cout <<dp[0];


}