#include <iostream>
using namespace std;

//어려우 ㅜㅜ

int r, c, tim;
int cleanrow;

int map[51][51];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int solve()
{
    for (int t = 0; t < tim; t++)
    {
        int vmap[51][51]= {0};

        //spread
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(map[i][j]<5) continue;
                int spread  = map[i][j] /5;
                for(int k=0; k<4; k++){
                    int ny= i + dy[k];
                    int nx = j + dx[k];
                    if(ny<0 || ny >r-1 || nx <0 || nx > c-1) continue;
                    if(map[ny][nx]==-1) continue;

                    vmap[ny][nx] += spread;
                    vmap[i][j] -= spread;

                }

            }
        }


        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                map[i][j] += vmap[i][j];
            }
        }


        //cleaner

        for (int i = cleanrow - 1; i >= 1; i--)
            map[i][0] = map[i - 1][0];

        for (int j = 0; j <= c - 2; j++)
            map[0][j] = map[0][j + 1];
        
        for (int i = 0; i <= cleanrow - 1; i++)
        {
            map[i][c - 1] = map[i + 1][c - 1];
        }
        for (int j = c - 1; j >= 2; j--)
        {
            map[cleanrow][j] = map[cleanrow][j - 1];
        }
        map[cleanrow][1] = 0;

        for (int i = cleanrow + 2; i <= r - 2; i++)
        {
            map[i][0] = map[i + 1][0];
        }
        for (int j = 0; j <= c - 2; j++)
        {
            map[r - 1][j] = map[r - 1][j + 1];
        }
        for (int i = r - 1; i >= cleanrow + 2; --i)
        {
            map[i][c - 1] = map[i - 1][c - 1];
        }
        for (int j = c - 1; j >= 2; j--)
        {
            map[cleanrow + 1][j] = map[cleanrow + 1][j - 1];
        }
        map[cleanrow + 1][1] = 0;
    }
    int sum = 0;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j]>0)
            sum += map[i][j];
         }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> tim;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j]==-1 && map[i-1][j] ==-1){
                cleanrow = i-1;
            }
    
        }
    }



    cout <<solve() <<'\n';

    return 0;
}
