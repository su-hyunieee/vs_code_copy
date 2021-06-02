//Lesson 5 Prefix Sums
// you can use includes, for example:
#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//50...점짜리...
int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)

    vector<long> v;


    for(long i= A; i<=B; i++){
        //K로로 나누고고 나눠지면면 넣고고 싸이즈즈 쿠하기기 ?
        if(i % K == 0){
            v.push_back(i);
        }
    }

    long ret = v.size();

    return ret;

}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
 //score 100 ... 수식 생각 시발!
int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int min, max;

        min = A/K;
        max = B/K;

        if(A % K ==0) min --;


        return max -min;


}