#include<iostream>
//#include<math.h>
using namespace std;


// 계산식을 생각해고 풀면 좋은 문제인듯
// 이딴걸로 고민한게 좆같음 ..

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int max_num =0;
    int sum =0;
            int num;

    

    cin >>n;

    for(int i=0; i<n; i++){
        cin >>num;
        sum+=num;
        max_num = max(num, max_num);
        
    }

    cout << sum + max_num*(n-2);
}