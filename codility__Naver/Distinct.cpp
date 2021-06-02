#include<iostream>
#include<set>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


//https://app.codility.com/demo/results/trainingKM9ZQU-ETT/


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<long> s;
    
    int len = A.size();
    long cnt =0;

    for(int i=0; i<len; i++){

        s.insert(A[i]);

    }
    cnt = s.size();

    return cnt;



}