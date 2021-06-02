#include <iostream>
#include <stdio.h>

using namespace std;

int n, L,R;
int map[50][50];

int visited[50][50];

int cnt;

int find(int r, int c, int value)
{
    if (r < 0 || r > n - 1 || c < 0 || c > n - 1) return 0;
    if (visited[r][c]) return 0;
    if (value != -1)
    {
        int diff = abs(value - map[r][c]);
        if (diff < L || diff > R) return 0;
    }

    visited[r][c] = 1;
    ++cnt;

    int sum = map[r][c];
    sum += find(r - 1, c, map[r][c]); // 이전 국가랑 차이
    sum += find(r + 1, c, map[r][c]);
    sum += find(r, c - 1, map[r][c]);
    sum += find(r, c + 1, map[r][c]);

    return sum;
}

void move(int r, int c, int value)
{

    if (r < 0 || r > n - 1 || c < 0 || c > n - 1)  return;
    if (visited[r][c] != 1)   return;
    visited[r][c] = 2; //1이면 연합국가 2면 최종인구수로 변경된 국가
    
    map[r][c] = value;
    move(r - 1, c, value);
    move(r + 1, c, value);
    move(r, c - 1, value);
    move(r, c + 1, value);
}

int solve()
{
    int ret = 0;
    bool flag;

    do
    {
        flag = false;

            //visited 0으로 초기화
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                 visited[i][j] = 0;
            
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {       //방문 ㄴㄴ 했으면
                if (visited[i][j] == 0)
                {
                    cnt = 0;
                    int sum = find(i, j, -1); //이전국가
                    if (cnt > 1)
                    {
                        flag = true;
                        move(i, j, sum / cnt);
                    }
                    else
                    {     //이미 통합된 국가는 2로
                        visited[i][j] = 2;
                    }
                }
            }
        }

        if (flag) ++ret;
    } while (flag);

    return ret;
}

int main()
{

    cin >> n >> L >> R;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            cin >> map[y][x];
        }
    }

    cout << solve() << endl;

    return 0;
}
