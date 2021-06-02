#include<iostream>
#include<set>
using namespace std;


int n;
set<int> s;


int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    scanf("%d", &n);


    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        s.insert(a);
    }

    set<int>:: iterator iter;
    for(iter= s.begin(); iter!=s.end(); iter++){
        cout << *iter <<'\n';
    }

    return 0;
}