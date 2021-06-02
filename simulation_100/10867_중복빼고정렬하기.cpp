#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

//set은 자동정렬

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    set<int> s;

    cin >>n;

    for(int i=0;i<n;i++){

        int a;
        cin>>a;
        s.insert(a);
    }

    set<int>::iterator iter;

    for(iter= s.begin(); iter!=s.end(); iter++){
        cout << *iter <<' ' ;
    }

    return 0;
}

