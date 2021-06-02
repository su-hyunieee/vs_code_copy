#include<iostream>
#include<string>
#include<algorithm>
#include<bitset>
#include<math.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int max_gap =0;
    int current_gap = 0;
    int reminder ;
    cin >>N;
    while(N>0 && N %2 ==0){
        N= N/2;
    }
    while (N>0)
    {
        reminder = N %2;
        if(reminder ==0){
            current_gap ++;
        }
        else{
            if(current_gap != 0){
                max_gap = max(current_gap, max_gap);
                current_gap =0;
            }
        }
        N = N/2;
    
    }
    

    cout << max_gap <<endl;














    // int position =0;
    // int max =0;
    // int cnt =0;
    // int max_gap =0;
    // int current_gep =-32;
    // cin>> n;

    // while(n>0){
    //     if(n % 2 ==1){
    //         current_gep =0;
    //     }
    //     else
    //     {
    //      current_gep += 1;
    //      max_gap =(1,2);
    //     }
    //     n = n/2;
        
    //     cout << max_gap<<endl;

    //     // bin[position] = n %2;
    //     // n = n/2;
    //     // position++;
    //     // if(n ==0) 
    //     //  break;
    // }
    
    // // for(int i= position -1; i >=0; i--){
    // //     if(max < cnt && bin[i] ==1) max = cnt;
    // //     if(i ==1) cnt =0;
    // //     else cnt+=1;

    // // }
    // // cout << max;


}