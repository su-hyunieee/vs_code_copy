#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//단지번호랑 비슷

//세로  가로
int n, m, k;
int map[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int cnt = 0;

void dfs(int y, int x)
{
    map[y][x] = 1;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ny < 0 || nx < 0 || ny >= m|| nx >= n)
            continue;

        if (map[ny][nx] == 0)
        {
            dfs(ny, nx);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    int x1, x2, y1, y2;

    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        for(int x = x1; x < x2; x++)
        {   
         for(int y = y1; y < y2; y++)
            {
                map[y][x] = 1;
            }
        }
    }

    vector<int> v;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!map[i][j])
            {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}