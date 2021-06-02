#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, ret = 987654321;
int map[20][20];
bool pick[20];

/*

dfs와 백트래킹을 통해서 모든 경우를 돌아보는 완전탐색 문제다.
dfs로 스타트 팀으로 뽑을 선수 번호를 뽑는다
스타트 팀으로 뽑은 선수가 N/2 명이 되면 두 팀의 능력치 차이를 구한다.
위 과정을 반복한다.

*/

void dfs(int cur, int pick_cnt)
{
    if (pick_cnt == (n / 2))
    {
                    //linker  start team
        vector<int> team_link, team_start;

        for (int i = 0; i < n; i++)
        {   //true면 start 팀에 넣고
            if (pick[i])
                team_start.push_back(i);
            else
                team_link.push_back(i);
        }

        int sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < team_start.size(); i++)
        {
            for (int j = i + 1; j < team_start.size(); j++)
            {

                int start_x = team_start[i];
                int start_y = team_start[j];

                int link_x = team_link[i];
                int link_y = team_link[j];
                
                sum1 += map[start_x][start_y] + map[start_y][start_x];
                sum2 += map[link_x][link_y] + map[link_y][link_x];
            }
        }

        ret = min(ret, abs(sum1 - sum2));
    }

    for (int i = cur ; i < n; i++)
    {

        if (pick[i] == false)
        {
            pick[i] = true;

            dfs(i+1, pick_cnt + 1);

            pick[i] = false;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> map[y][x];
        }
    }


    dfs(0, 0);


    printf("%d\n", ret);
}