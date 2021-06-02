#include <iostream>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long ret[91];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ret[0] = 0;
        ret[1] = 1;
        ret[i + 2] = ret[i] + ret[i + 1];
    }

    cout << ret[n] ;
}