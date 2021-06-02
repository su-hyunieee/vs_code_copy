#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;




int main(){
    print({ {0, 3}, {1, 9}, {2, 6} }, 9);
    print({ {0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}}, 13);
    print({ {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3}}, 13);
    print({ {0, 3}, {4, 4}, {5, 3}, {4, 1} }, 3);
    print({ {0, 3}, {1, 9}, {500, 6} }, 6);
    return 0;
}