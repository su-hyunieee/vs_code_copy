#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

// 식 만들고 
// 포문만. .잘 . . 생각해서 꼭 돌려주면.. 되..


int main(){

        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);    

        int n;
        int arr[100001] ;
        int ret =0;
        cin >>n;

        for(int i=0; i<n; i++){

            cin >> arr[i];
        }
        sort(arr, arr+n);

        
     for(int i=n-1; i>=0; i--){

        arr[i] = arr[i] * (n-i);
        if( ret< arr[i])
            ret = arr[i];
        }

    cout <<ret;

}