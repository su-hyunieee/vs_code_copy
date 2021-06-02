// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingDCVA77-MHK/

int solution(int K, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int cnt =0;
    int sum =0;

    for(int i=0; i< (int)A.size(); i++){

        sum += A[i];

        if(sum >= K){
            cnt ++;
            sum =0;
        }

    }

    return cnt ;
}