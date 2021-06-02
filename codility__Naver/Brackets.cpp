// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingJPUD2Z-N3Z/
int solution(string &S)
{
    // write your code in C++14 (g++ 6.2.0)

    stack<char> st;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '{' || S[i] == '(' || S[i] == '[')
        {
            st.push(S[i]);
        }
        else
        {
            if (st.empty())
                return 0;

            char c = st.top();
            st.pop();

            if (c == '(' && S[i] != ')')
                return 0;
            if (c == '{' && S[i] != '}')
                return 0;
            if (c == '[' && S[i] != ']')
                return 0;
        }
    }

    if (st.empty())
        return 1;
    else
        return 0;
}
