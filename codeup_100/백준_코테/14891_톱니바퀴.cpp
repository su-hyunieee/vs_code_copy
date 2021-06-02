#include <iostream>
#include <stdio.h>
using namespace std;

/*
 맞닿은 극이 같으면 회전 x 
 맞닿은 극이 다르면 내가 한거랑 반대방향으로 회전


*/

int k;
int target, cmd;
char gear[4][9];

int main()
{

    for (int i = 0; i < 4; i++)
    {
        cin >> gear[i];
    }

    //회전횟수
    cin >> k;

    while (k--)
    {
        cin >> target >> cmd;
        --target; // 나는 0부터 시작하니까 빼주고 시작
        //입력저장
        int move_cmd[4] = {  0,};

        move_cmd[target] = cmd; //타겟을 어떻게 움직였다

        //타겟의 왼쪽 이니까 반대로 돌아
        for (int left = target - 1; left >= 0; left--)
        {
            int right = left + 1;
            //왼쪽2 =오른쪽6 같으면 안 움직이고
            if (gear[left][2] == gear[right][6])
            {
                break;
            }
            else
            {   //다르면 반대방향
                move_cmd[left] = move_cmd[right] * -1;
            }
        }

        //타겟의 오른쪽
        for (int right = target + 1; right < 4; right++)
        {
            int left = right - 1;
            if (gear[left][2] == gear[right][6])
            {
                break;
            }
            else
            {
                move_cmd[right] = move_cmd[left] * -1;
            }
        }

        for (int i = 0; i < 4; i++)
        {   //오르쪽으로 돌아라면
            if (move_cmd[i] == 1)
            {   //7을 임시저장
                char temp = gear[i][7];
                //반대로 돌면서 저장
                for (int j = 7; j >= 1; --j)
                {
                    gear[i][j] = gear[i][j - 1];
                }
                gear[i][0] = temp;
            }
            if (move_cmd[i] == -1)
            {

                char temp = gear[i][0];
                for (int j = 0; j < 7; j++)
                {
                    gear[i][j] = gear[i][j + 1];
                }
                gear[i][7] = temp;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        //s 극이면 1 2 4 8 증가 이거 시프트 연산 시발롬아
        if (gear[i][0] == '1')
        {
            ret += (1 << i);
        }
    }

    cout << ret << endl;

    return 0;
}