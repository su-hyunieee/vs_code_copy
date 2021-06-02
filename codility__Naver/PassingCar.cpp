// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//https://app.codility.com/demo/results/trainingVE8BXM-N8Z/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    long zero=0;
    unsigned int ret=0;
   int n = A.size();

    for(int i = 0; i<n; i++){

        if(A[i]==0) 
            zero++;
        else{
            ret+=zero;
        }
    }

    if( ret >1000000000 || ret  < 0)return -1;
    
    return ret;

 }
int main()
{
    int k = 5;
    vector<int> A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    A.push_back(1);
    A.push_back(1);
    solution(A);
}