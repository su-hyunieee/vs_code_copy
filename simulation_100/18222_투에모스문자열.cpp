#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

string getN(string st ){
  string str = "";

  //cout << st[0];
  for (int i = 0; i < st.size(); i++)
  {
    if (st[i] == '0'){
      str += "1"; 
    }
    else if(st[i] == '1'){
      str += "0";
    } 
  }

  return str;
}

int main()
{

  n = 2;

  string st = "01";

  for(int i=2; i<= n; i++) {
    st[n] = to_st[n-1] + getN(st[n-1]);
  }





 
}
