#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;


/*
이 문제는 나랑..
안맞는듯. ..
*/

struct CCTV
{
    int type, y, x;
};

int n, m, ret;
int map[8][8];
CCTV cctv[8];
int cctv_size;

                    //각자 도는 경우의 수
const int rot_size[] = {4, 2, 4, 4, 1};

void map_copy(int a[8][8], int b[8][8])
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            a[y][x] = b[y][x];
        }
    }
}

void update(int dir, CCTV cctv)
{
    dir = (dir % 4);
    
    //동쪽
    if (dir == 0)
    {
        for (int x = cctv.x + 1; x < m; x++)
        {
            if (map[cctv.y][x] == 6) break;
               
            map[cctv.y][x] = -1; //감시 완료
        }
    }
    //북쪽
    if (dir == 1)
    {
        for (int y = cctv.y - 1; y >= 0; --y)
        {
            if (map[y][cctv.x] == 6)
                break;

            map[y][cctv.x] = -1;
        }
    }
    //서쪽
    if (dir == 2)
    {
        for (int x = cctv.x - 1; x >= 0; --x)
        {
            if (map[cctv.y][x] == 6)
                break;
            map[cctv.y][x] = -1;
        }
    }
    //남쪽
    if (dir == 3)
    {
        for (int y = cctv.y +1; y <n ; ++y)
        {
            if (map[y][cctv.x] == 6)
                break;

            map[y][cctv.x] = -1;
        }
    }
}

        //  cctv  개수임
void dfs(int cctv_index)
{
    if (cctv_index == cctv_size)
    {
        //빈공간 찾아서 업데이트
        int candi =0;
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                if(map[y][x]==0){
                    candi++;
                }
            }
        }

        ret = min(ret, candi);
        
        return;
    }

    int backup[8][8];
    //걍 이름 줄인거임
    int type = cctv[cctv_index].type;

    //사이즈만치 반복문
    for (int dir = 0; dir < rot_size[type]; dir++)
    {
        //map backup
        map_copy(backup, map);
    
        //0번 카메라면 
        if (type == 0)
        {   
            update(dir, cctv[cctv_index]);
        }
        else if (type == 1)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
        }
        else if (type == 2)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
        }
        else if (type == 3)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
        }
        else if (type == 4)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
            update(dir + 3, cctv[cctv_index]);
        }

        dfs(cctv_index + 1);
        map_copy(map, backup); // 이게. . 백트랙킹. . .
        //map recovery
    }

}



int main()
{
    cin >> n >> m;


    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];

            //find cctv 
            if (map[y][x] != 0 && map[y][x] != 6)
            {
                cctv[cctv_size].y = y;
                cctv[cctv_size].x = x;
                cctv[cctv_size].type = map[y][x] - 1;
            
                ++cctv_size; // cctv count
            }
        }
    }

    ret = 100; 
    dfs(0);

    cout << ret << endl;

return 0;
}