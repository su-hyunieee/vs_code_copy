#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//https://cryptosalamander.tistory.com/12

string c;

int a[26] ;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max =0;
    int cnt =0;
    int target =0;

    cin >> c;
    
    transform(c.begin(), c.end(), c.begin(), (int(*)(int))toupper) ;
    
    for(int i= 0; i< c.size(); i++){
      //  cout << a[i] <<" ";
        
        a[c[i] - 'A']++;
    }

    for(int i=0; i< 26; i++) {
        if(max < a[i]){
            max = a[i] ;
            cnt =0;
            target  =i;
        }
        if(max == a[i]){
            cnt ++;
        }
    }

    if(cnt >1 )
        cout << "?" ;
    else
    {
        cout << (char)(target +'A'); //int + 'A' 하면 대문자로 출력;
    }
    
    return 0;

}