#include <iostream>
using namespace std;

//CCW 법칙 ? 외적 해서 푸는
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;

    cin >> x1 >>y1 >>x2 >>y2 >>x3 >>y3;


    if (x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1) == 0)
    {
        cout << '0' << '\n';
    }
    else if (x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1) > 0)
    {
        cout << "1" <<'\n';
    }
    else if (x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1) < 0)
    {
        cout << "-1" <<'\n';
    }

    return 0;
}