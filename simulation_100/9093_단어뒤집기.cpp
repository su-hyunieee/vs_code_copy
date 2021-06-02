#include <iostream>
#include <algorithm>
#include<stack>
#include <string>
using namespace std;

int t;


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t; 

    cin.ignore() ; // or  string s; getline(cin, s) ; 이렇게 해도 됨. .;;
    

    while (t--)
    {
        string str, temp;
        getline(cin ,str) ;

        for(int i=0; i< str.size(); i++) {
            if(str[i]== ' '){
                reverse(temp.begin(), temp.end());
                cout << temp << ' '; 
                temp.clear(); // 출력했으면 비워준다.
            }
            else{
                temp += str[i] ;
            }
        }

        reverse(temp.begin(), temp.end()); // 마지막 단어 
        cout << temp <<'\n';


    }
    


    
}