#include<iostream>
using namespace std;

int main(){
    int x =10, y = 85, d =30;
    int temp =0;
    int n = 1;
    while( 1){
        if(x>=y){
            cout << "0" ;
        }
        temp = x + d*n;
        if(temp >= y){
            break;
        }
        else{
            n++;
        }
    }

    cout <<n ;



}