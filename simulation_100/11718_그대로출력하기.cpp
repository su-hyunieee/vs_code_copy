#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


char arr[100];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL) ;

    for(int i=0; i<100; i++){
        cin.getline(arr, 101) ;
        cout << arr << "\n" ;
    }

}
