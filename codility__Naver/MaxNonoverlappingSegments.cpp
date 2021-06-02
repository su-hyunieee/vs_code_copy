#include<iostream>
#include<vector>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingPQW897-JNJ/
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() < 1) return 0;


    int cnt =1;
    int ret = B[0];

    for(int i =0; i< (int)A.size(); i++){

        if(A[i]>ret){
            cnt ++;
            ret = B[i];
        }

    }

    return cnt ;





}