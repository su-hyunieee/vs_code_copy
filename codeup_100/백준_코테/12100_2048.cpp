#include<stdio.h>
#include<iostream>
using namespace std; 

int n;
int ret ;
struct BOARD{
    int map[20][20];

    //90도 돌리기
     void rotate(){
            int temp[20][20];
         for (int y = 0; y < n; y++)
         {
             for (int x = 0; x < n; x++)
             {
              temp[y][x] = map[n-x-1][y];
             }
         }
     
        for (int y = 0; y < n; y++)
         {
             for (int x = 0; x < n; x++)
             {
                 map[y][x] = temp[y][x];
             }
         }
     }

     int get_max()
     {
         int ret =0;
         for (int y = 0; y < n; y++)
         {
             for (int x = 0; x < n; x++)
             {
                if(ret < map[y][x]){
                    ret = map[y][x];
                }
             }
         }
     return ret;
     }

    void up(){

        int temp[20][20];

        for (int x = 0; x < n; x++)
        {
            int flag = 0, target = -1;
            for (int y = 0; y < n; y++)
            {
                //up시키는 경우
                if(map[y][x]==0){
                    continue;
                }
                //똑같은거 만나서 들른경우
                if(flag ==1 && map[y][x]==temp[target][x]){
                    temp[target][x] *=2, flag =0;
                }else{
                // 그냥 한칸 올라가는 경우
                temp[++target][x] = map[y][x]; flag=1;
                }
            }
        
            for(++target; target<n; target++){
                temp[target][x]= 0;
            }
     
        }
           
        for (int y = 0; y < n; y++)
         {
             for (int x = 0; x < n; x++)
             {
                 map[y][x] = temp[y][x];
             }
         }
    }


};

void dfs(BOARD cur, int count){
    int candi = cur.get_max();

    if(count == 5){
        if(ret < candi){
            ret = candi;
        }
    return ;
    }


    //4way rotate
    for(int dir=0; dir<4; dir ++){
        BOARD next =cur;
        next.up();
        dfs(next, count+1);
        cur.rotate();

    }

}


int main()
{

    cout << "STARRT" << endl;

    BOARD board;
    scanf("%d", &n);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%d", &board.map[y][x]);
        }
    }
    ret =0;
    
    dfs(board, 0);

    printf("%d", ret);

return 0;



}

// //2048
// #include <stdio.h>


// int n;   // whole map
// int ret; // max

// struct BOARD
// {
//     int map[20][20];

//     //회전해주는거. .90도?
//     void rotate()
//     {
//         int temp[20][20];

//             //오른쪽으로 구십도 회전
//         for (int y = 0; y < n; ++y)
//         {
//            for (int x = 0; x < n; ++x)
//             {
//                 temp[y][x] = map[n-x-1][y];
//             }
//         }
//         //map temp에 복사
//         for (int y = 0; y < n; ++y)
//         {
//            for (int x = 0; x < n; ++x)
//             {
//                 map[y][x]=temp[y][x]  ;
//             }
//         }
//     }

//     int get_max()
//     {
//         int ret =0 ;
      
//         for (int y = 0; y < n; ++y)
//         {
//            for (int x = 0; x < n; ++x)
//             {
    
//                 if(ret<map[y][x]){
//                     ret = map[y][x];
//                 }

//             }
//         }
//         return ret;
//     }

//     void up()
//     {
//          //가로부터 돌아야 댐
//          // 한 번 갱신이 일어나면 연속으로 갱신이 안 된다
//         int temp[20][20];
        
//         //가로부터 도니까
//         for(int x=0;x<n; ++x){
//                             //행 바로아래있는거 더할거
//             int flag = 0, target = -1; // temp에 복사하기 위해 Target점 복사
//             for(int y=0; y<n; ++y){
//                     if(map[y][x]==0){
//                         continue;
//                     }
//                         // 2랑 2 만나면 합치는거
//                     if(flag == 1 && map[y][x]==temp[target][x]){
//                         temp[target][x] *= 2, flag =0;
//                     }else{
//                         //위치하나 올라감
//                         temp[++target][x] = map[y][x], flag= 1;
//                     }
//             }

//             for(++target; target<n; ++target){
//                 temp[target][x] = 0;
//             }            

//         }
//     //보드 복사 다시 해줘    
//     for (int y = 0; y < n; y++)
//     {
//         for (int x = 0; x < n; x++)
//         {
//             map[y][x] = temp[y][x];
//         }
//     }

//     }

// };

// void dfs(BOARD cur, int count){
//     if(count ==5){
//         int candi =cur.get_max();

//         if(ret < candi){
//             ret = candi;
//         }
//         return;
//     }

//     for(int dir=0; dir<4; ++dir){
//         BOARD next = cur;
//         next.up(); //한번실행
//         dfs(next, count+1);
//         cur.rotate(); //돌려
//     }

// }



// int main()
// {
    
//     BOARD board;
//     scanf("%d", &n);

//     for(int y=0; y<n; ++y){
//         for(int x=0; x<n; ++x){
//             scanf("%d", &board.map[y][x]);
//         }
//     }

//     ret = 0;

//     dfs(board,0);
//     printf("%d\n", ret);

//     return 0;
// }
