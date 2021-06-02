#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<set>
using namespace std;



int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> s;
    int n = A.size();
    for(int i=0; i<n; i++){
        
        int temp = A[i];
        
        s.insert(temp);

        if(s.size() ==X){

            return i;
        }

    }
    return -1;

}


int main()
{
    int k = 5;
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(1);
    A.push_back(4);
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
      A.push_back(4); 
    int ret =0;
    ret =solution(5,A);
    cout <<ret ;
}