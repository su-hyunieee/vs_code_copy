#include <iostream>
#include <algorithm>
#include <string>
#include<queue>
using namespace std;

int cnt = 1;
string str;



int main()
{

    getline(cin, str);
    

    for(int i=0; i< str.size(); i++){
        if(str[i] == ' ') cnt ++;
    }

    if(str[0] == ' ') cnt--;
    if(str[str.size()-1] == ' ') cnt --;

    cout << cnt ;


    // string str;

    // getline(cin, str);

    // long long nBlank = count(str.begin()+1, str.end()-1, ' ');

    // long long cnt = nBlank +1;

    // cout << cnt ;
}
