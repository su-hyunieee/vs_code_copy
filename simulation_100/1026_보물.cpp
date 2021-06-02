#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> A;
vector<int> B;

int ans;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        B.push_back(b);
    }

    sort(A.begin(), A.end());

    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        ans += A[i] * B[i];
    }

    cout << ans;

    return 0;
}