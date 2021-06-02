#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

stack<int> oper;  //숫자 
stack<char> oper_rand; //연산자
int a = 0;


//replaceall string 안되길래 구글링해서 찾음 ㅎㅋ 굳이 이렇게 까지 안 해도 댐
std::string ReplaceAll(std::string &str, const std::string &from, const std::string &to)
{
  size_t start_pos = 0;                                                //string처음부터 검사
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) //from을 찾을 수 없을 때까지
  {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
  }
  return str;
}

//연산자 우선순위 
int Priority(char ch)
{
  if (ch == ')')
    return 5;
  else if (ch == '^')
    return 4;
  else if (ch == '*' || ch == '/')
    return 3;
  else if (ch == '+' || ch == '-')
    return 2;
  else
    return 1;
}

//infix to postfix 
string infixTopostfix(string infix)
{
  string postfix;
  char ch = 0;

  string::iterator i = infix.begin();

  //배열로 할랬는데 iterator로 했는데
  //그래서 계산할때 공백처리가 ㅈㄴ 귀찮았음
  for (; i != infix.end(); ++i)
  {
     a = 0;
    //피연산자면 postfix에 넣기
    if (isdigit(*i))
    {
      postfix += *i;
      postfix += ' ';
    }
    else if (*i == '(')
    {
      oper_rand.push(*i);
    }
    else if (*i == ')')
    {
      ch = oper_rand.top();
      oper_rand.pop();
      if (oper_rand.empty())
      {
        cout << "Incorrect" << endl;
        a = 1;
        break;
      }

      while (ch != '(')
      {
        postfix += ch;
        postfix += ' ';
        ch = oper_rand.top();
        oper_rand.pop();
      }
    }
    else
    {
      if (oper_rand.empty())
        oper_rand.push(*i);
      else
      {
        while (!oper_rand.empty())
        {
          //연산자 스택에 있는게 우선순위가 높으면 그거 빼서 postfix에 넣기
          if (Priority(oper_rand.top()) >= Priority(*i))
          {
            ch = oper_rand.top();
            oper_rand.pop();
            postfix += ch;
            postfix += ' ';
          }
          else
          {
            break;
          }
        }
        oper_rand.push(*i);
      }
    }
  }

  while (!oper_rand.empty())
  {

    if (oper_rand.top() == '(')
    {
      a = 1;
      cout << "Incorrect" << endl;

      while (!oper_rand.empty())
      {
        oper_rand.pop();
      }
      break;
    }

    postfix += oper_rand.top();
    postfix += ' ';
    oper_rand.pop();
  }

  if (a == 0)
  {
    cout << postfix << endl;
    
  }
  return postfix;
}

void Calculate(string postfix)
{
  char ch = 0;
  int num1, num2, result;
  int a;
  string::iterator it = postfix.begin();

 //굳이 이렇게 한게 ㄹㅇ 별로긴 한데 .. 방법이 생각 안났음 ;;
  ReplaceAll(postfix, std::string(" "), std::string(""));

  for (; it != postfix.end(); ++it)
  {

    if (isdigit(*it))
    { //int 스택에 들어가야 돼서 int로 바꿨는데 atoi가 string거라는걸 몰랐음 ;;
      a = *it - '0';
      oper.push(a);
    }
    else
    {
      ch = *it;
      if (oper.empty())
      {

        cout << "Calculation Error" << endl;
        break;
      }
      num1 = oper.top();
      oper.pop();
      if (oper.empty())
      {

        cout << "Calculation Error" << endl;
        break;
      }
      num2 = oper.top();
      oper.pop();

      if (ch == '+')

        result = num2 + num1;

      else if (ch == '-')

        result = num2 - num1;

      else if (ch == '*')

        result = num2 * num1;

      else if (ch == '/')

        result = num2 / num1;

      else if (ch == '^')

        result = pow(num2, num1);

      oper.push(result);
    }
  }

  if (!oper.empty())
  {
    cout << oper.top() << endl;
    oper.pop();
  }
}

int main()
{
  string infix;
  string postfix;
  int result;
  int n;
  cout << "start" << endl;
  
  cin >>n;
  for(int i=0; i<n; i++){
   cin >> infix;
  postfix = infixTopostfix(infix);
  if (a == 0)
  {
    Calculate(postfix);
  }
  cout <<endl;
  }
}