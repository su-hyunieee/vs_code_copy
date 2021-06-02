#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



string str;
string al = "abcdefghijklmnopqrstuvwxyz";
int main() {

    cin >> str;

    for(int i=0; i< al.size() ;i++) {
        cout << (int)str.find(al[i]) <<" " ;
    }

    


}