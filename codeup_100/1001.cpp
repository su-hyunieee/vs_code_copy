#include <iostream>
#include<cmath>
using namespace std;

int main()
{

    long long int a, r, n;
    long long int result;
    long long int s;

    scanf("%lld %lld %lld", &a, &r, &n);

    s = pow(r, n-1);

    result = s*a;
    printf("%lld", result);

    return 0;
}