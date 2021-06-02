#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*

복잡하게 생각 ㄴㄴ 해 . . .. . 
.. . .
*/

pair<int, int> p[1000001];


bool compare(pair<int, int>a, pair<int, int> b){
    if( a.second == b.second){
        return a.first< b.first;
    }
    else{
        return a.second < b.second;
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;


    cin >>n;

    for(int i=0;i<n; i++){

        cin >> p[i].first >> p[i].second;

    }

    sort(p, p+n, compare);


    int highLink = p[0].second;
    int cnt =1;
    for(int i=1; i< n; i++){

        if( highLink <= p[i].first){
            cnt ++;
            highLink = p[i].second;

        }
     //   cout <<pq.top() <<endl;
    }


        cout <<cnt<<endl;
}