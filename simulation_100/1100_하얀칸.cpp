#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string map[8] = {
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW"
            };

string chk[8];

int main()
{

    for (int i = 0; i < 8; i++)
    {
        cin >> chk[i];
    }


    int cnt= 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chk[i][j] == 'F' && map[i][j] == 'W')
            {
                cnt ++;
            }
        }
    }

   cout << cnt;
}