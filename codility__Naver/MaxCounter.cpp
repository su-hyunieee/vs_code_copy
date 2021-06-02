#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    vector<int> v(N,0);
    int max = 0, chk =0 ; 

    for(int i=0;i< len;i++){
        if(A[i] == N+1){
           max == chk;
        }
        else{
            if(v[A[i]-1]< max) 
   
        }
    }

  

    return v;

}

int main()
{
    int k = 5;
    vector<int> A;
    A.push_back(3);
    A.push_back(4);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);
    A.push_back(4);
    A.push_back(4); 
    int ret =0;
    solution(5,A);
}