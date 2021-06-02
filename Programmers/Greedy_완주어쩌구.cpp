#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> part, vector<string> comp) {
    sort(part.begin(), part.end());
    sort(comp.begin(), comp.end());
    
    for(int i=0; i<part.size(); i++){
        if(part[i]!= comp[i]){
            return part[i];
        }
    }

    return part[part.size()-1];
 }