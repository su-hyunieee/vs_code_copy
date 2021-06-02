#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
백트랙킹이랑 나는 정말. .
안맞는다 씨발. . 
bfs를 쓰기엔 이상한데 최단거리를 구한다 ? 그럼 백트랙킹이라고 생각. . 
*/

string tar;
int answer = 987;

bool isvisited[51];

void dfs(string begin, vector<string> words, int ret)
{

    if (begin == tar)
    {
        answer = min(ret, answer);
        return;
    }
    for (int i = 0; i < words.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            if (begin[j] != words[i][j])
                cnt++;
            if (cnt == 2)
                break;
        }
        if (cnt == 1)
        {
            if (isvisited[i] == false)
            {
                isvisited[i] = true;
                dfs(words[i], words, ret + 1);
                isvisited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{

    ios::sync_with_stdio(false);

    tar = target;

    dfs(begin, words, 0);

    if (answer == 987)
        answer = 0;

    return answer;
}