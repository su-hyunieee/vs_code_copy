#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int ret ;


int main(){

    cin >>n;

    vector<int> v;

    for(int i=0; i<n; i++){
        int a;
        cin >>  a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

     
    do{
        int tmp =0;
        for(int i=0; i< v.size() -1; i++){
            tmp += abs(v[i] - v[i+1]);
        }
        
        ret = max(ret, tmp);
    }while (next_permutation(v.begin(), v.end()));

    cout << ret;

}