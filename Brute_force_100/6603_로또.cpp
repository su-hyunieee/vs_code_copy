#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*  
    순서없이, 중복없이 돌리기면 매 재귀마다 시작점을 넘겨준다
    순서 ㅇㅇ 중복 ㅇㅇ 돌리기면 하나 정해두고 다 돌린다.
    https://ikso2000.tistory.com/78
    이 문제에서 아주 좋은 스킬 하나 배울 수 있다 생각한다.

예를 들어 7개의 숫자가 있는데, 이중 내가 6개의 숫자를 골라야 한다.소스를 통해 확인해보자

아! 일단 여기서 알아야 할게 순열은 중복되는 것은 걸러버린다. 예를 들어 설명하면

d 라는 벡터에 [0] = 0, [1] = 1, [2] = 1, [3] = 1, [4] = 1 , [6] = 1; 이 있고, 순열을 돌리면

0 1 1 1 1 1 1

1 0 1 1 1 1 1

1 1 0 1 1 1 1

1 1 1 0 1 1 1

1 1 1 1 0 1 1

1 1 1 1 1 0 1

1 1 1 1 1 1 0 요로코롬 중복을 제외되면서 출력된다.


*/

int k;
int lotto[13] ;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        int n;
        cin >> n;
        if(n == 0 )break;

        vector<int> v;

        for(int i =0; i<n; i++){
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        
        //6개 뽑기
        vector<int> d;
        //7개중에 6개를 뽑는다 그럼 7-6은 0 나머지는 1 
        for(int i=1; i <= n-6; i ++){
            d.push_back(0);
        }
        for(int i=1; i<=6; i++){
            d.push_back(1) ;
        }

        vector<vector<int>> res;

        do{
            vector<int> tmp;
            for(int i=0; i<n; i++)
                //1이면 숫자 넣기 0은 선택 안한거
                //선택한거면 숫자 넣기
                if(d[i]) tmp.push_back(v[i]);
            //다 넣고는 이중 배열에 넣기
            res.push_back(tmp);    
        }while (next_permutation(d.begin(), d.end()));
    
        //정렬
        sort(res.begin(), res.end());


        for(int i=0; i<res.size(); i++){
            for(int j =0; j< res[i].size(); j++){
                cout << res[i][j] <<' ';
            }
            cout << '\n';

        }

        cout <<'\n' ;

    }
    


    return 0;
}








// int k;
// int lotto[13];
// int visitied[13];
// void cal(int cnt, string ans, int start)
// {
//     if (cnt == 7)
//     {
//         cout << ans << '\n';
//     }
//     else
//     {
//         for (int i = start; i < k; i++)
//         {
//             if (visitied[i] == 1)
//                 continue;

//             visitied[i] = 1;
//             cal(cnt + 1, ans + to_string(lotto[i]) + " ", i + 1);
//             visitied[i] = 0;
//         }
//     }
// }

// int main()
// {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int tmp;
//     while (1)
//     {
//         cin >> k;

//         if (k == 0)
//             break;
//         for (int i = 0; i < k; i++)
//         {
//             cin >> tmp;
//             lotto[i] = tmp;
//             visitied[i] = 0;
//         }
//         cal(1, "", 0);
//         cout << '\n';
//     }
// }