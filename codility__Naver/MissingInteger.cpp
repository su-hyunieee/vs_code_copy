// you can use includes, for example:
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(),A.end());
    int min =1;
    int n = A.size();

    //젤 작은애가 1이니까 1이면 올리고 2면 올리고 이렇게 
    for(int i=0; i<n; i++){
        if(A[i]==min) min+=1;
    }
    //이거 다 아니면 걍 1 
    return min;
}