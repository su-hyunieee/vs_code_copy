#include <iostream>
using namespace std;
//예외 찾는게 ㅈ같음
//문제는 안어려운데 0 0 0 왜 굳이 낌? 


int main()
{

    int l, p, v;
    int cnt = 1;

    while (1)
    {
        cin >> l >> p >> v;

        if (l == 0 && p == 0 && v == 0)
        {
            break;
        }
        else
        {

            int day = (v / p);
            int last = v % p > l ? l : v % p; //연산식 존나 일학년때 보고 처음

            int ret = day * l + last;

            cout << "Case " << cnt++ << ": " << ret << endl;
        }
    }

    return 0;
}