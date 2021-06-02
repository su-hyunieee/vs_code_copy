#include<iostream>
using namespace std; 

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n ;
 
 cin >>n;

for(int i= 1; i<n ; i++){
    int temp = i;
    int num = i;

    while (temp>0)
    {
        num += temp %10 ;
        temp /= 10;

    }

    if( n == num ){
        cout << i <<"\n" ;
        return 0;
    }
  
    
}
cout <<"0" ;






}