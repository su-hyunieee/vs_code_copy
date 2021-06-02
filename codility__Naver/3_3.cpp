// you can use includes, for example:
// #include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include<numeric>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//score : 53 tq

//수정하고 100  ㅆㅃ 수학적 사고 존나 부족

vector<int> v;
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    int front = 0;
    int end = accumulate(A.begin(), A.end(), 0);
    int Min = -99999999;
    int result =0;

    for(int i=0; i< n-1 ;i ++){
        front+= A.at(i);
        end -= A.at(i);
        Min= abs(front - end);
        v.push_back(Min);
    }

    result = *min_element( v.begin(), v.end() );
 
    return result;
}

int main()
{

    vector<int> A;

    A.push_back(3);
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    A.push_back(3);
    int ret ;
   ret = solution(A);
   cout <<ret ;
}