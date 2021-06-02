#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int isvisited[9] ;
vector<int> v;


void dfs(){
    if(v.size() == n){
        for(int i=0; i<v.size(); i++){
            cout << v[i]  <<" ";
        }
        cout <<"\n" ;
    }

    for(int i=1; i<=n; i++){

        if(isvisited[i]==false){
            isvisited[i] = true;
            v.push_back(i);
            dfs();
            isvisited[i] = false;
            v.pop_back();
          }
    }


}


int main(){


    cin >>n;

    dfs();

    return 0;

}