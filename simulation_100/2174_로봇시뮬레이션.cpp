#include<iostream>
#include<vector>
using namespace std;

// 다시 풀기
//https://regularmember.tistory.com/198
int A,B,N,M;

int check[101][101];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

struct Robot{
int x, y, dir;
Robot(int a, int b, int c){
    x = a;
    y = b;
    dir = c;
}

};

vector<Robot> vt;
int main(){
    cin >> A >>B;
    cin >> N >> M;

    int x, y, dir;
    char d;
    vt.push_back(Robot(-1,-1,-1));

    for(int i=1; i<=N; i++){
        cin >> x>> y >> d;

        if(d =='N') dir = 1;
        else if(d == 'E') dir = 2;
        else if(d == 'S') dir = 3;
        else dir = 0;

        vt.push_back(Robot(x,  y, dir));
        check[x][y] = i;
    }

    int num;
    char order;
    int cnt;

    int crash_w = 0;
    int last = 0;
    int crash_r  =0;

    while (M--)
    {
     cin >> num >>order >> cnt;

     if(crash_w || crash_r) continue;

     x = vt[num].x;
     y = vt[num].y;
     dir = vt[num].dir;

    while (cnt --)
    {
        if(order == 'L'){
            dir = (dir+3 )%4;
            vt[num].dir = dir;
        }
        else if(order == 'R'){
            dir = (dir+1 )%4;
            vt[num].dir = dir;
        }
        else if(order == 'F'){
            check[x][y] = 0;
            
             y = y + dy[dir];
             x = x + dx[dir];

            if(x <1 ||  y <1 || x> A || y > B) {
                crash_w = num;
                break;
            }
            else if(check[x][y]!= 0){
                last = num;
                crash_r = check[x][y];
                break;
            }else{
                vt[num].x = x;
                vt[num].y = y;
                check[x][y] = num;
            }

        }
    }
    

    }
    
    if(crash_w) cout << "Robot " << crash_w <<" crashes into the wall \n";
    else if(crash_r) cout<<"Robot " << crash_r <<" crashes into robot\n";
    else {
        cout <<"OK\n" ;
    }

    return 0;
}


