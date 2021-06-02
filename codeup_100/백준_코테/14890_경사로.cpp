#include <iostream>
#include<stdio.h>
using namespace std;
//존나 어렵다 개 ㅆ발

/*

다음거랑 높이 같으면 cnt ++
오르막 앞에 유효거리가 > l이면 다리 놓을수 있고 cnt =1
내리막 앞에랑 상관 없음 근데 cnt>=0 이면 삐져나가지 ㄴㄴ
cnt = 1-l로 update

*/

int map[200][100];
int n, l ,ret =0;


int main()
{

//    cin >> n >> l;

    scanf("%d %d" , &n, &l);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%d",&map[y][x]);
        }
    }


    //새로 맵만 보기 위해서 구십도 돌리고 아래에 붙히기
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            map[n + y][x] = map[x][y];
        }
    }

    int cnt = 0;
    int i, j;
     ret =0 ;
    for (i = 0; i < (2 * n); i++)
    {   //맨앞은 1로
        cnt = 1;
        for (j = 0; j < (n - 1); j++)
        {
                // 다음이랑 같으면 +
            if (map[i][j] == map[i][j + 1])
            {
                ++cnt;
               //cout <<" same cnt" <<cnt <<endl;
            }   // 오르막길 만남, , 앞에 유효거리가 길이보다 크면 
            else if (map[i][j] + 1 == map[i][j + 1] && cnt >= l)
            {   //다음꺼 cnt =1 // 다리 놓기 가능
                cnt = 1;
            }   //내리막길 만나고 안 삐져나오면
            else if (map[i][j] - 1 == map[i][j + 1] && cnt >= 0)
            {       //미리 계산 해주는거 
                cnt = (1 - l);
            }
            else
            {   //다리 못놔
                break;
            }
        }
        //끝까지 다 돌고 안 삐져 나오면
        if(j == (n - 1) && cnt >= 0)
        {   //길 추가
            ++ret;
           
        }
    }

    cout << ret << endl;
}
