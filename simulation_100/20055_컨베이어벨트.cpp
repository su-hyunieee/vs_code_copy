#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

//2020하반기 

deque<bool> robot; //로봇 움직임
deque<int> dq; //내구도

int n, k;
int x;
int ans =0;

int find()
{
    int ret = 0;

    for (int i = 0; i < dq.size(); i++)
    {
        if (dq[i] == 0)
        {
            ret++;
        }
        
    }
    return ret;
}

void move()
{

    while (1)
    {
        if (find() >= k) break; // 0 이 k보다 크면 break;

        ans++;

        //move belt
        dq.push_front(dq.back());
        dq.pop_back();
        //move robot
        robot.push_front(robot.back());
        robot.pop_back();
        //돌다가 내릴 위치면 내린다
        if (robot[n-1] == true)   robot[n-1] = false;

        //맨앞에는 로봇이 있고 윗줄만 움직이면 된다
        for (int i = n - 2; i >=0 ; i--)
        {   //로봇이 있고 다음칸에 내구성이 1이상이면서 다음칸에 로봇이 없으면
            if (robot[i] == true && dq[i + 1] >= 1 && robot[i + 1] == false)
            {
                dq[i + 1]--; //내구성 줄이고
                robot[i] = false; //원래칸에 애 비우고
                if (i == n - 2) continue; // 다음칸이 내리는 칸이면 나간다
                robot[i + 1] = true; //내리는칸이 아니면 로봇 true
            }
        }

       // 0번에 로봇올리기
        if (dq[0] >= 1 && robot[0] == false)
        {
            robot[0] = true;
            dq[0]--;
            
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    scanf("%d %d", &n, &k);

    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%d", &x);
        dq.push_back(x);
        robot.push_back(false);
    }

    move();

    printf("%d\n", ans );

    return 0;
}