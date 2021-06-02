#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
using namespace std;

// score : one hundred~~
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    set<int> s;

    long n = A.size();
    long ret = 0;
    long sum = (n + 1) * n / 2;
    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
    {
        int temp = A[i];
        s.insert(temp);
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        ret += *i;
    }
    if (ret == sum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int k = 5;
    vector<int> A;
    A.push_back(4);
    A.push_back(1);
    A.push_back(3);
    A.push_back(2);

    int ret = 0;
    ret = solution(A);
    cout << ret;
}