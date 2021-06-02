// you can use includes, for example:
// #include <algorithm>
#include<bitset>
#include<vector>
#include<iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can use includes, for example:
// #include <algorithm>
#include<bitset>
#include<vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//https://app.codility.com/demo/results/trainingF8XS4A-5E3/

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    string str = bitset<32>(N).to_string();
    vector<int> v;
    int gap =0;
    for(int i=0; i< (int)str.size(); i++){

        char bin = str[i];

        if(bin == '1'){
            v.push_back(i);
        }
    }

    if(v.size()>1){
        for(int i=0; i< (int)v.size() -1; i++){
            int tmpGap = v.at(i+1) - v.at(i) -1;
            if(gap < tmpGap){
                gap =tmpGap;
            }
        }
    }




    return gap;

}