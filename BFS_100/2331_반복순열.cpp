#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300001

//dfs는 이용당했다
//이런문제도 있구나 ..

int isvisited[MAX];
int a, p;
int cnt = 0;

void dfs(int num)
{
    isvisited[num]++;

    if (isvisited[num] == 3)
    {
        return;
    }

    int sum = 0;

    //이거 십진수 5,7 이렇게 나누는 코드
    //자주나오네 시발롬
    while (num)
    {
        sum += pow((num % 10), p);
        num /= 10;
    }

    dfs(sum);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 57;

    cin >> a >> p;

    dfs(a);

    for (int i = 0; i < MAX; i++)
    {
        if (isvisited[i] == 1)
            cnt++;
    }
    cout << cnt;
}
