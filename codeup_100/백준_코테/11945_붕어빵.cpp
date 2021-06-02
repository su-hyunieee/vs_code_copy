#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{

    int n, m;
    string s;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        reverse(s.begin(), s.end());
         cout << s <<"\n";
    }
}