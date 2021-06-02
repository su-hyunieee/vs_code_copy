#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int w[11][11];

// 완탐

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }

    vector<int> v(n - 1);

    // 0 1    1 2    2 3    3 4
    for (int i = 1; i < n; i++)
    {

        v[i - 1] = i;
    }

    //1 2 3
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    int ret = 987654321;

    do
    {

        bool flag = true;
        int sum = 0;
        // 0 1 2
        for (int i = 0; i < n - 2; i++)

        {
            if (w[v[i]][v[i + 1]] == 0)
            {
                flag = false;
                break;
            }
            else
            {
                sum += w[v[i]][v[i + 1]];
            }
        }
        if (flag == true)
        {
            if (w[0][v[0]] && w[v[n - 2]][0])
            {
                sum += w[0][v[0]] + w[v[n - 2]][0];
                ret = min(ret, sum);
            }
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << ret;
}