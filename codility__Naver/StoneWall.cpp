// you can use includes, for example:
// #include <algorithm>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingKRTHYH-U9V/
int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)

    int cnt =0;
    stack<int> st;

    for(int i=0; i< (int)H.size(); i++){

        while(!st.empty() && st.top()>H[i]){
            st.pop();

        }
        if(st.empty() || st.top() <H[i]){
            st.push(H[i]);
            cnt ++;
        }

    }



    return cnt; 


}