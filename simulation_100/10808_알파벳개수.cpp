#include<iostream>
#include<string>
#include<algorithm>
using namespace std;




int res[26] ;

int main(){
    string str ;
  //  string alp ="abcdefghijklmnopqrstuvwxyz";
    

    cin >>str ;

    for(int i=0; i< str.size() ;i++) {
        res[str[i] - 'a']++;
    }
    
    for(int i=0; i< 26; i++){
        cout << res[i] << " ";
    }




}