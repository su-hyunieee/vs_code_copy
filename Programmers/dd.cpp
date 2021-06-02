#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1000000007
long long ret ;
long long sum;

int main(int argc, char** argv)
{
        int k ,p, n;

        cin >> k>> p >> n;

        sum = pow(p,n);
        ret = (k * sum) % MAX;

        cout <<ret ;




 return 0;
}
