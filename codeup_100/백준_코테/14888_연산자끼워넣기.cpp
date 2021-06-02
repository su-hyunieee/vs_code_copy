#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int A[11];
int op[4];
int ret_min = 1000000000, ret_max = -1000000000;

void dfs(int result, int count)
{
    if (count == n - 1)
    {
        if (ret_min > result)
        {
            ret_min = result;
        }
        if (ret_max < result)
        {
            ret_max = result;
        }
        return;
    }
    
    //backtracking
    for (int i = 0; i < 4; i++)
    {
        if (op[i] != 0)
        {
            --op[i]; //연산자 썼으니까 개수 줄여주고
            if (i == 0)
            {
                //      다음항
                dfs(result + A[count + 1], count + 1);
            }
            else if (i == 1)
            {

                dfs(result - A[count + 1], count + 1);
            }
            else if (i == 2)
            {
                dfs(result * A[count + 1], count + 1);
            }
            else if (i == 3)
            {
                dfs(result / A[count + 1], count + 1);
            }

            ++op[i]; //다시 또 와야 되니까 다시 늘려주고
        }
    }
}

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++)
    {

        cin >> op[i];
    }

    dfs(A[0], 0);


    printf("%d\n%d\n", ret_max, ret_min);
}