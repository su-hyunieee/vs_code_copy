#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
 65 -90 대문자
 97 - 122 소문자
*/



string str;
int sm =0, bg=0, spa=0, num=0;

int main(){
    
    while (getline(cin, str, '\n'))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                ++sm; //대문자
            }
            else if (str[i] >= 97 && str[i] <= 122)
            {
                ++bg; //소문자
            }
            else if (str[i] == ' ')
            {
                ++spa;
            }
            else
            {
               ++num;
            }
        }

        cout << bg << " " << sm << " " << num << " " << spa << '\n';
        sm = 0, bg =0, num =0, spa =0;
    }   
    return 0;
}
