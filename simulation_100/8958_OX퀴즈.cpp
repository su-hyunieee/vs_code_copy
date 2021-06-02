#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int n;
int cnt ;
int score ;
//char arr[81] ;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin::tie(NULL) ;
    cout.tie(NULL);
    cin >> n;

    for(int i=0; i<n; i++){
        cin >>s;

        for(int i =0; i< s.size(); i++){
                if(s[i] == 'O'){
                    cnt ++;
                    score += cnt;
                }
                if(s[i] == 'X'){
                    cnt =0;
                }
        }

        cout << score <<'\n' ;
        
        cnt =0;
        score =0;
    }


}