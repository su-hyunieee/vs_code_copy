#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        stack<char> st;
        string ans = "YES";
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (!st.empty() && s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = "NO";
                break;
            }
        }

        if (!st.empty())
            ans = "NO";

        cout << ans << '\n';
    }
}
