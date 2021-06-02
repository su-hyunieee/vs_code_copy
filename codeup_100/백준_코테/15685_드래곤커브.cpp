#include <iostream>
#include <vector>
using namespace std;

/*
0 ->
1 위
2 <-
3 아래

*/

//              오른쪽 위 왼쪽 아래
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int map[101][101];

int solve()
{

    int ret = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            //Map돌면서 나 내 양옆 아래 그어저 있으면 사각형 완성
            if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
            {
                ++ret;
            }
        }
    }

    return ret;
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false) ;
     


    int n;

    cin >> n;

  

    for (int i = 0; i < n; ++i)
    {
          vector<int> curves;
  
        int x, y, d, g;
        //start
        cin >> x >> y >> d >> g;

        curves.push_back(d);

        //드래곤 커브 세대에 따라 증가
        for (int j = 0; j < g; j++)
        {
            //앞세대 거꿀로 둘면서 +1 돌면서 넣기
            for (int k = curves.size() - 1; k >= 0; k--)
            {
                curves.push_back((curves[k] + 1) % 4);

            }
        }

        map[y][x] = 1;
        
           vector<int>::iterator iter=curves.begin(); 

        //벡터 순회하면서 선 그어주기
        for (iter = curves.begin(); iter != curves.end(); ++iter){
            x += dx[*iter];
            y += dy[*iter];
            map[y][x] = 1;
        }
    }

    cout << solve() << endl;

    return 0;
}