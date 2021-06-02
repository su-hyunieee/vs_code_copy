#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n;
int s ;
vector<int> v(20) ;
//n개의 정수로 이루어진 수열이 있을 떄 크기가 양수인
//부분수열중세ㅓ 그 수열의 원소를 다 더한값이 ㄴs 가 되는거 

int ans ;


void dfs(int i, int sum){
    if( i == n) return ;

    if(sum + v[i] == s ){
        ans ++;
    }

    dfs(i+1, sum) ;
    dfs(i + 1 , sum + v[i]);
}



int main(){

    cin >>n >>s;

    for(int i=0; i<n; i++) {
        cin >>v[i] ;
    }
    dfs(0,0);

    cout<< ans<<'\n';
    return 0;
}