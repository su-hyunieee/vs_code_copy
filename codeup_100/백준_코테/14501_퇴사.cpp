#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int t[15], p[15], m[15];


int dp(int day){

    if( day> n) return -987654321;
    if(day == n) return 0;

    int ret = max(dp(day+1), dp(day +t[day]) + p[day]);

    return ret;


}



int main(){

cin >>n;

for(int i=0; i<n; i++)
{

    cin >> t[i] >> p[i]; 
    m[i] = -1; // 돈은 초기화
 }

int ret =    dp(0);


cout <<ret <<endl;



}

















// #include<stdio.h>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// int n;
// int t[15], p[15];
// int cache[15];

// int solve(int day){

// if( day > n) return -987654321;
// if(day ==n ) return 0; //7일째는 일을 못햐

// int& ret = cache[day];
// if(ret!=-1) return ret;

// ret = max(solve(day+1), solve(day+ t[day]) + p[day]);

// return ret;
// }


// int main(){


//     scanf("%d", &n);
    
//     for(int i=0; i<n; i++){

//         cin>> t[i] >> p[i];

//         cache[i] = -1;

//     }
//    int ret = solve(0);

// cout <<ret<<endl;





// }