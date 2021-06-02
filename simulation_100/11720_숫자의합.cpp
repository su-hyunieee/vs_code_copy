#include<iostream>
#include<algorithm>
using namespace std;


int n ;
char n2;
int sum ;

int main(){


    cin >>n;
    

    for(int i=0; i< n; i++){

        cin >> n2;

        cout  << n2- '0'  << '\n';

        sum  += (n2 - '0') ;
    
    }

     cout << sum <<'\n' ;


}