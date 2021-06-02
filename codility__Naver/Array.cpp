#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int temp =9;

    for(int i=0; i < A.size(); i++){
   //   temp ^=A[i];
   //   cout <<temp <<endl;
      
    }

    
    temp ^= 3;

    cout <<temp;


    
    
   // cout << temp ;

    
    return temp;
}


int main()
{
    int k = 1;
    vector<int> A;
    A.push_back(9);
    A.push_back(3);
    A.push_back(9);
    A.push_back(3);
    A.push_back(9);
    A.push_back(7);
    A.push_back(9);

    solution(A);
}