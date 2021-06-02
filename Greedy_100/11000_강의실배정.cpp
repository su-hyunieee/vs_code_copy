#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//greater 오름차순
//priority queue
//식 세워서 구현하면 된다 pq 첨 써봐서 당황 황당 ..;

pair<int, int> p[200001];

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return  a.first< b.second;
    }
    else{
        return a.second < b.second;
    }
}


//오름차순으로 쓰려면 <int , vector<int>, greater<int>>
//내림차순으로 쓰려면 <int> pq 이런식으로 쓰면 ㅇㅋ
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, compare);

    pq.push(p[0].second);

    for (int i = 1; i < n; i++)
    {
        if (pq.top() <= p[i].first)
        {
            pq.pop();
            pq.push(p[i].second);
        }
        else
        {
            pq.push(p[i].second);
        }
    }

    cout << pq.size() << endl;

    return 0;
}