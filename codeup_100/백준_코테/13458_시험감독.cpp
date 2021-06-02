#include<iostream>
#include<stdio.h>
using namespace std;


//총감독은 1명은 꼭 있어야 되고 
//부감독은 있어도 없어도 ㄱㅊ
//전제 - 총감독이 맡은거 - 부감독
//long long - 8 , lld


int n;
int b,c;

int map[1000000];

int main(){


scanf("%d", &n);

//정보 받아야지
for(int i=0; i<n; i++)
{
    scanf("%d", &map[i]);

}

scanf("%d %d", &b,&c);

long long ret = 0;
// 전체에서 b를 빼주고 
// 전체를 ++
for(int i=0; i<n; i++){
    map[i] -=  b;
    ret ++;
    if(map[i]>0){
        int boo = map[i] / c;

        if(map[i] % c != 0){

            ++boo;
        }

    ret += boo;
    }


}

printf("%lld\n", ret); 
    return 0;
}