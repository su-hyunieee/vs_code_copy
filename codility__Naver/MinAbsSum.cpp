// you can use includes, for example:
 #include <algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<iostream>
#include<set>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int main(){


    set<int> s;
    vector<int> A;
    vector<int> B;

    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    A.push_back(3);
    
     B.push_back(1);
    B.push_back(3);
    B.push_back(4);
    B.push_back(3);

  
  for(int i=0; i<A.size(); i++){
      s.insert(max(A[i],B[i]));
  }
   
    set<int>::iterator iter;

    for(int i=1; i<=99999999; i++){
        iter = s.find(i);
        if(iter!= s.end()) {
            return 1;
            
        }else{
            cout <<i <<endl;
            return i;
        }
    }



    return 1;

//  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
// 		cout << *it << " ";
// 	}
}











//1
// int solution(string &S, vector<int> &C) {
//     // write your code in C++14 (g++ 6.2.0)
    
   
//     vector<int> v;
//     int len = S.size();
//     int cnt =0;

    
//     for(int i=0;i < len; i++){

//         if(S[i]==S[i+1]){
            
            
//             v.push_back(C[i]);
            
//         }
        
//     }

//     vector<int>::iterator iter = v.begin();

//     if(v.empty()){
//     return 0;
//     } else{
//         for(iter = v.begin(); iter!=v.end(); ++iter )
//             {
//                 cnt += *iter;
//             }
//     }

//     return cnt;


// }




//2번

// // you can use includes, for example:
// #include <algorithm>
// #include<queue>
// #include<functional>

// // you can write to stdout for debugging purposes, e.g.
// // cout << "this is a debug message" << endl;

// int solution(vector<int> &A, int K) {
//     // write your code in C++14 (g++ 6.2.0)
//     vector<int> even;
//     vector<int> odd;
//     int e_sum=0;
//     int o_sum =0;
//     int sum =0;
//     int n = A.size();

//     if(n < K) return -1;

//     for(int i=0; i<n; i++){
//         if(A[i]%2 == 0) {
//           even.push_back(A[i]);
  
//         }
//         else{ odd.push_back(A[i]);
//         }
//     }

//     sort(even.begin(), even.end(),greater<int>());
//     sort(odd.begin(),odd.end(),greater<int>());
    
//     int len = K - even.size();

//     if(even.size() ==0) return -1;
//     if((int)even.size() >= K){
//         for(int i=0; i<K; i++){
//             sum+=even[i];
//         }
//          return sum;

//     }
//     else{
//         for(int i=0; i< (int)even.size(); i++){
//             e_sum += even[i];
//         }
//         for(int i=0; i < len; i++){
//             o_sum += odd[i];
//         }
//     }


//     return e_sum + o_sum ;


// }
