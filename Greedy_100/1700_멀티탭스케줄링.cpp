#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 씨발 진짜 모르겠다 

int n ,m;
int use[101];
int res;
vector<int> plug;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //2 7
    cin >>n >>m; 

    for(int i=0; i<m; i++)
    {
        cin>> use[i];
    }

    for(int i=0; i<m; i++){
        // empty space dd
        if(plug.size() < n){
            vector<int>::iterator iter = find(plug.begin(), plug.end(), use[i]);
            if(iter == plug.end()){
                plug.push_back(use[i]);
            }
            continue;
        }
        vector<int>::iterator iter = find(plug.begin(), plug.end(), use[i]);
        if(iter != plug.end()){
            continue;
        }
        int val =0, lastindex =0;
        for(int j=0; j<n; j++){
            int cnt =0;

            for(int k= i +1; k<m; k++){
                if(use[k]== plug[j]){
                    break; //다음에 꽂혀있다 넘어가
                }
                cnt++; //다르면 ++ 
            }
            //마지막에 쓰이는거
            if(cnt > lastindex){
                val = j;
                lastindex= cnt;
            }
        }
        res ++;
        //맨 마지막에 쓰이는걸 뽑는다 맨마지막 자리에 넣는거지 . .
        plug[val] = use[i];
    }
    cout <<res <<endl;
    }


//    //plug 계속 도는거 
//     for(int i=0; i<5; i++){
//         cout << "*" <<endl;
//      for(int k=0; k<5; k++){
//                 if(use[k]== plug[i]){
//                     break; //다음에 꽂혀있다 넘어가
//                 }
//                  cnt++;
//                  cout <<cnt <<endl;
//                  cout << "plug: "<< plug[k]<<endl;
                 
              
//             }
//     }

