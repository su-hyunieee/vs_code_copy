// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<iostream>
#include<vector>
using namespace std;

//https://app.codility.com/demo/results/training4WYV3X-47A/

//수학 잘하는넘이 ..ㅇㅋ
/*
    2,3만 고려 4이상은 의미없다. .
    update 해주는거 가슴으로 이해 못하지만..
    받아...그래야ㅣㅈㅣ

*/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)0;


    if(A.size() <2) 
    {return 0;
    }
    int ret=0;

    double min = (A[0]+ A[1])/ 2.0;
    double two =0,three =0;

    for(int i=2; i< (int)A.size(); i++){
        two =(A[i-1] + A[i]) / 2.0;
        three=(A[i-2]+A[i-1]+A[i])/3.0;

        if( two < min) 
        {
            min = two;
            ret= i-1;
        }
        if(three< min){
            min = three;
            ret= i-2;
        }

    }


    return ret;



}