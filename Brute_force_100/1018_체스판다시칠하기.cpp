#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int n, m;
int result = 987654321;
int map[51][51];
int bc[8][8];
int wc[8][8];

void sol(int y, int x)
{
    int tmp, tmp1;
    tmp = tmp1 = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (map[i + y][j + x] != bc[i][j])
                tmp++;
            if (map[i + y][j + x] != wc[i][j])
                tmp1++;
        }
    }

    result = min(result, tmp);
    result = min(result, tmp1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'W')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }

    //fill a White map and Black map
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            wc[i][j] = (i + j + 1) % 2;
            bc[i][j] = (i + j) % 2;
        }
    }

    //8칸씩 짜르니까 7넘어가면 볼 필요가 ㄴㄴ
    for (int y = 0; y < n - 7; y++)
    {
        for (int x = 0; x < m - 7; x++)
        {
            sol(y, x);
        }
    }
    cout << result;
}