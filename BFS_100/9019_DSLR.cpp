#include <iostream>
#include <queue>
#include<cstring>
#include <string>
using namespace std;

int start, End;
bool isvisited[10000];

string bfs(int s)
{
    queue<pair<int, string>> q;

    q.push(make_pair(s, ""));
    isvisited[s] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        string st = q.front().second;
        q.pop();

        if (x == End) return st;

        int nx = x * 2;
        if (nx > 9999)
        {
            nx = nx % 10000;
        }
        if (isvisited[nx] == false)
        {
            isvisited[nx] = true;
            q.push(make_pair(nx, st + "D"));
        }

        nx = x - 1;
        if (nx < 0)
            nx = 9999;
        if (isvisited[nx] == false)
        {
            isvisited[nx] = true;
            q.push(make_pair(nx, st + "S"));
        }
        //L
        nx = (x % 1000) * 10 + (x / 1000);
        if (isvisited[nx] == false)
        {
            isvisited[nx] = true;
            q.push(make_pair(nx, st + "L"));
        }
        nx = (x % 10) * 1000 + (x / 10);
        if (isvisited[nx] == false)
        {
            isvisited[nx] = true;
            q.push(make_pair(nx, st + "R"));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        memset(isvisited, false, sizeof(isvisited));

        cin >> start >> End;

        string ans = bfs(start);

        cout << ans << "\n";
    }
}
