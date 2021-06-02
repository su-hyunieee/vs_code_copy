// you can use includes, for example:
// #include <algorithm>
#include<stack>
#include<iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingBNZHQC-NQ5/
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;

    stack<int> up ;
    stack<int> down;

    for(int i=0; i< (int)A.size(); i++){

        if(B[i]==1){
            down.push(A[i]);
        }
        else{
            while(!down.empty()){
            int dfish = down.top();

                if(dfish > A[i]) break;
                else down.pop();
            }
            if(down.empty()) cnt++;
        }
      
    }
        return down.size() + cnt;
    }

