// you can use includes, for example:
#include <algorithm>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingHAARGH-ZWC/
//score 91
int solution(vector<int> A) {
    // write your code in C++14 (g++ 6.2.0)

    int half = A.size() /2;
    int cnt =-1;
    int ret =0;
    
    queue<int> q;
    for(int i=0; i< (int)A.size(); i++){
       
        cnt = count(A.begin(), A.end(), A[i]);

        //cout << cnt << endl;
        if(cnt > half){
            q.push(i);
            ret = q.front();
            break;
         }
    }

     
    return q.empty() ==1 ? -1:ret;
}

int main(){

int ret =0;
    vector<int> A;
    A.push_back(3);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    A.push_back(3);
    A.push_back(-1);
    A.push_back(3);
    A.push_back(3);

    ret =solution(A);
cout <<ret;

}