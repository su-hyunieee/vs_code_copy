// you can use includes, for example:
// #include <algorithm>
#include<stack>
#include<iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//100
//https://app.codility.com/demo/results/training263MMF-AXN/
int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt =0;

    for(int i=0; i<(int)S.size(); i++){
  
        if(S[i]=='(') cnt++;
        if(S[i]==')') cnt--; 

        if(cnt <0) return 0;
    }

    return cnt == 0? 1:0;


}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


//100
#include<stack>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> st;

    for(int i= 0 ;i <(int)S.size(); i++){
        if(S[i]== '(') st.push(S[i]);
        else{
            if(st.empty()) return 0;
            else{
                st.pop();


            }
        }

    }
  //  if(st.empty()) return 1;

    return st.empty() == 1? 1 :0;



}