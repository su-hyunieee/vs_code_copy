#include<iostream>
#include<queue>
using namespace std;
#define Max 100001
    //수빈이, 목적지
int n,k;
int ret =0;

bool isvisited[Max];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >>n >>k;

    queue< pair<int ,int > > q;
    
    q.push(make_pair(n, 0));
//    isvisited[n] = true; 계산하다가 n 될수도 있으니까 true nonono

    while (!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if(pos == k) 
        {   
           ret = cnt;
           break;
        }
        
        if(pos +1 < Max && isvisited[pos +1 ]==false){
            q.push(make_pair(pos+1, cnt +1));
            isvisited[pos+1] =true;
        }
        if(pos -1 >= 0 && isvisited[pos-1]==false){
            q.push(make_pair(pos-1, cnt +1 ));
            isvisited[pos-1] =true;
        }
        if(pos *2 < Max && isvisited[pos*2]==false){
            q.push(make_pair(pos*2, cnt +1));
            isvisited[pos*2] = true;
        }

    }

    cout <<ret  ;
    return 0;

}