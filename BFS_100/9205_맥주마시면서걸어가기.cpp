

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//편의점을 기준으로 돌면서 bfs


int t, n;

vector<pair<int, int> > cu;

int res;

bool bfs(int y, int x)
{
    bool chk[101] = {false};

    chk[0] = true;
    queue<pair<int, int> > q;
    
    q.push(make_pair(y, x)); // 시작점

    res = 0;

    while (!q.empty())
    {
        int here_y = q.front().first;
        int here_x = q.front().second;
        q.pop();

        for (int i = 0; i < cu.size(); i++)
        {
            if (abs(here_y - cu[i].first) + abs(here_x - cu[i].second) <= 1000 && chk[i] == false)
            {
                q.push(make_pair(cu[i].first, cu[i].second));
                chk[i] = true;
            }
        }
    }

    return chk[n + 1]; //도착점
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cu.clear();

        for (int i = 0; i < n + 2; i++)
        {
            int x, y;

            cin >> y >> x;
            cu.push_back(make_pair(y, x));
        }

        //첫 위치 넣기
        bool ret = bfs(cu[0].first, cu[0].second);

        if (ret)
        {
            cout << "happy\n";
        }
        else
        {
            cout << "sad\n";
        }
    }

    return 0;
}