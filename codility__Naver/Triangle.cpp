// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


//93 score 그냥 넘어가자 
//A[i] -> 범위 초가 long으로 따로 변수받아서 하면 될듯
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
   
   sort(A.begin(), A.end());

for(int i=0; i< (int)A.size() -2; i++){
   if(A[i] + A[i+1]> A[i+2]){
       return 1;
   }

}

   return 0;




}