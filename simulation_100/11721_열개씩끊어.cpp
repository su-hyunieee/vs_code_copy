#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int main()
{

    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
        if ((i + 1) % 10 == 0)
        {
            cout << '\n';
        }
    }
    
    cout << "\n";
}