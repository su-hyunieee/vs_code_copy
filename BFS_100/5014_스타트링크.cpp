#include <iostream>
#include <queue>
using namespace std;

//ssibbal rom
// . . .Tlqkffha..

    //전체, 나 ,목적지, 업, 다운
int f, s, g, u, d;

bool isvisited[1000001];

queue<pair<int, int> > q;

int bfs()
{
    q.push(make_pair(s, 0));
    isvisited[s] = true;
    
    while (!q.empty())
    {
        int cnt = q.front().second;
        int pos = q.front().first;

        q.pop();

        if(pos == g) return cnt ;

        if(pos + u <=f && isvisited[pos+u]==false){
            q.push(make_pair(pos+u, cnt + 1));
            isvisited[pos+u]= true;
        }
        if(pos- d > 0 && isvisited[pos-d]==false){
            q.push(make_pair(pos-d, cnt +1) );
            isvisited[pos-d] = true;
        }
    }
    
    //못가 비에픙스 못돌았어
    return -1;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    cin >> f >> s >> g >> u >> d;

    int res = bfs();

    if (res == -1)
    {
        cout << "use the stairs";
    }
    else
    {
        cout << res;
    }

    return 0;
}