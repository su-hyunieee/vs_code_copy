#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

/*
 정렬 된거에서 모든 경우의 수 해보는거 -> next_permutation
 atoi() -> char to int
 stoi() -> string to int 

*/

 // 소수 찾는 방법 에라토스테네스의 체 ?
bool isPrime(int n) {
    if (n < 2) return false;
 
    // 에라토스테네스의 체
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
 
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    
   do{
        for(int i=1; i <=numbers.size();i ++){
             x = stoi(numbers.substr(0, i));
                cout << x  << endl;
            
            if(isPrime(x) == true) s.insert(x) ;
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    


    return 0;
}