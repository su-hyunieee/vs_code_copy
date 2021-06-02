#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
char map[51][51];

void vertical()
{

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;

        for (int j = 0; j < n; j++)
        {

            if (map[j][i] == map[j + 1][i])
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
    }
}

void horizonal()
{

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {

            if (map[i][j] == map[i][j + 1])
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    //가로로 돌리기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            char tmp;
            tmp = map[i][j];
            map[i][j] = map[i][j + 1];
            map[i][j + 1] = tmp;

            //vertical, horizonal
            vertical();
            horizonal();

            tmp = map[i][j];
            map[i][j] = map[i][j + 1];
            map[i][j + 1] = tmp;
        }
    }

    //세로로 돌리기
    for (int i = 0; i < n; i++)
    { //행
        for (int j = 0; j < n - 1; j++)
        { //열

            char tmp;
            tmp = map[j][i];
            map[j][i] = map[j + 1][i];
            map[j + 1][i] = tmp;

            //vertical, horizonal
            vertical();
            horizonal();

            tmp = map[j][i];
            map[j][i] = map[j + 1][i];
            map[j + 1][i] = tmp;
        }
    }

    cout << ans;

    return 0;
}