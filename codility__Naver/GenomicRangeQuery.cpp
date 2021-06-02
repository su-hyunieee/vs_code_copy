// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> dna[5]; 
    int len = S.size();

    for(int i=0; i< len; i++){
        switch(S[i]){
            case  'A' : 
                dna[1].push_back(i); 
                break;
            case  'C' :     
                dna[2].push_back(i);
                break;
            case 'G' : 
                dna[3].push_back(i);
                break;
            case 'T' : 
                dna[4].push_back(i);
                break;
    }
}

int main(){
    String S ="CAGCCTA";
    
    if()


}