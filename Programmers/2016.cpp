#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string day[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int sum = 0;
    for(int i =1; i< a; i++){
        sum += month[i-1] ;
    }
    sum += b-1;
    
    string answer = day[sum % 7];
    return answer ;
}