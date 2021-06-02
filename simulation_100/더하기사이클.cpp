#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int n, n1, n2,n3;
int cnt = 1;

int main(){

    cin >>n;

    int chk = n;
    while (1)
    {
        n1 = n/10 ;
        n2 = n%10 ;
        n3  = n1 + n2;

        n = n2*10 + n3 %10;

        if(chk ==n){
            break;
        }else{
            cnt ++;
        }
    }
    


cout << cnt ;



}

