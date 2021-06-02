#include<iostream>
#include<algorithm>
using namespace std;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n; // people
    int time[1001] ={0}; // 초기화 배열 다 쓸거니까 근데 시간 잡아 먹은듯
    int result=0;
    cin >>n ;

    for(int i=1; i<=n; i++){

        cin >> time[i];
    }

    sort(time, time +n+1);


    for(int i=1; i<=n; i++){

        time[i] = time[i-1] +time[i];

        
        result += time[i];
    }




cout <<result;     

}