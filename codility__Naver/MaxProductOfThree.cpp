// you can use includes, for example:
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingAE66VR-NDV/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();

    sort(A.begin(), A.end());
    int maximun =0;
    maximun = A[len-1] * A[ len -2]* A[len -3];
   int  max_2 = A[len-1]*A[0]*A[1];
    int ret = max(maximun,max_2);

return ret;



}



int main(){


    vector<int> A;
    A.push_back(-3);
    A.push_back(1);
    A.push_back(2);
    A.push_back(-2);
    A.push_back(5);
    A.push_back(6);
    solution(A);
}
