#include<iostream>
#include<algorithm>
using namespace std;


int year;

int main(){

    cin >> year;

    if( year %4 == 0 && year %100 !=0 || year %400 ==0 ){
        cout << "1" ;
    }
    else{
        cout <<"0" ;
    }
    


    return 0;
}