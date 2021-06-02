#include<iostream>
#include<algorithm>
using namespace std;


int a, b, c;
int ret ;
int arr[10] ;



int main(){

    cin >> a >> b>> c;

    ret = a *b * c;

    while (ret >0)
    {
        arr[ret %10] ++;

        ret /=10 ;
    }
    
    for(auto a : arr){
        cout << a  <<'\n';
    }

}