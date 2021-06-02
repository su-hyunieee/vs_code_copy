#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string a, b ;
int result = 987654321;
int cnt ;

int main(){

    cin >> a >> b ;


    for(int i=0; i<= b.length() - a.length(); i++){
        cnt = 0;
        for(int j=0; j< a.length(); j++){
            if(a[j] != b[j+ i]) cnt ++;
        }

       result = min(result, cnt) ;
    }

    cout << result;
    return 0;
}