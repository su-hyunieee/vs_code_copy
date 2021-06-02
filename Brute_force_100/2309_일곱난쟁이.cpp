#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int arr[9];
int sum;
int n=9;

int main()
{

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort( arr, arr+ n);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(sum - arr[i] - arr[j] ==100){
                for(int x =0; x<n; x++){
                    if(x ==i || x ==j) continue;
                    cout << arr[x] <<"\n";
 
                   }
                return 0; // 끝내기 출력하고
            }
        }

    }
return 0;
}