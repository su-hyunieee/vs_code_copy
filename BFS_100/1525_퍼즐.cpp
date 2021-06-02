#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;

/*
신박하게 빡치게함 시발롬
string -> map 하는거 기억해두기 . .
set은 중복 안 되니까 visited로 쓰기 .. ~
*/

string Start, End;
set<string> visit;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs()
{
    queue<pair<string, int> > q;
    q.push(make_pair(Start, 0)); // 시작점이랑, 움직인 횟수 넣기
    visit.insert(Start);

    while (!q.empty())
    {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == End)  return cnt; //원하느 상태가 됐다면

        int zero = cur.find('0'); //움직일 0의 위치를 찾는다
        int x = zero / 3;
        int y = zero % 3;

        for (int i = 0; i < 4; i++)
        {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx >= 0 && ny >= 0 && ny < 3 && nx < 3)
            {
                string next = cur;
                swap(next[x * 3 + y], next[nx * 3 + ny]); // 원래자리랑 상하좌우 바꿔준다

                //없는거라면 움직인다
                if (visit.find(next) == visit.end())
                {
                    visit.insert(next);
                    q.push(make_pair(next, cnt + 1));
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    End = "123456780"; // 원하는 상태

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int a;
            cin >> a;
            Start += to_string(a);
            //받고 스타트에 저장
        }
    }

    cout << bfs();
}