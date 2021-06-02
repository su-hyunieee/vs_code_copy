// you can use includes, for example:
 #include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    long n = A.size();
    long ret =0;
    long temp = ((n+1)*(n+2))/2;
    
    for(int i=0; i< n; i++){
        ret += A[i];
    }

    long result = temp -ret;

    return result;

}