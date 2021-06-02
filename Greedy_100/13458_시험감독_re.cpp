#include<iostream>
using namespace std;


int main(){
       ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);    

     int n ;
     int  b, c;
     int boo=0;
     long long ret =0;
     int map[10000001];

     cin >>n;

    for(int i=0; i<n; i++){
        cin  >> map[i];
    }

    cin >> b>> c;

    for(int i=0; i<n; i++){
        map[i] -= b;
        ret ++;
        if(map[i]>0){
            boo = map[i]/c;

            if(map[i]%c != 0){
                boo++;
            }
                ret += boo;
        }

    }

    cout <<ret <<endl;
}