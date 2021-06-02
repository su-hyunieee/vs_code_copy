#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

/*
왜 알고리즘이 대갈 싸움인지 알겠당 ㅋ 문제 해석이 존ㄴ ㅏ어렵고 이게 
먼 개소리야 싶은 문제다 . . 이렇게 푸는거 알아서 . .다음엔 이렇게 
접근해보도록 노력은 하겠지만 그떄도 못할거 같아 뿌잉..ㅜ
*/

char dna[1001][51];

int hd,Max=0;

//해밍거리 같으면 사전순이라서 acgt로 해야 되는데 이거 맘대로 했다가 존나 안 돼서 노트북 부실까 고민함
char Change(int a, int t, int g, int c, int Max){
    if(Max ==a) return 'A';
    else if(Max == c) return 'C';
    else if(Max == g) return 'G';
    else return 'T';


}



int main(){



    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt =0;

 
    int n,m;
    
    cin >> n>> m;
    for(int i=0; i<n; i++){
        cin >> dna[i];
    }

    for(int i=0; i<m; i++){
            int a=0, t=0 ,g=0,c=0 ;

        for(int j=0; j<n; j++){
            switch (dna[j][i])
            {
            case 'A': a++; break;
            case 'T': t++; break;
            case 'G': g++; break;
            case 'C': c++; break;
            }

        }

        Max = max(a, max(t,max(g,c)));
        hd += (n-Max);
        cout << Change(a,t,g,c,Max);
        
    }

    cout <<"\n"<< hd;


}