#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    int re;
    string s;

    cin >> t;

    for(int i=0; i<t; i++ )
    {
        cin >> re >> s ;

        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i < re; i++)
            {
                cout << s[j];
            }
        }

        cout <<"\n" ;
    }
}