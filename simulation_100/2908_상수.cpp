#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s1, s2;


int main() {

    cin >> s1 >> s2;

    char temp = s1[0] ;
    s1[0] = s1[2] ;
    s1[2] = temp;


    char temp2 = s2[0] ;
    s2[0] = s2[2] ;
    s2[2] = temp2;

    if(s1 > s2) {
        cout << s1;
    }
    else{
        cout << s2 ;
    }
    

}
