#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//이정도는 풀수있는데 왜 생각하기가 싫쥐 ? ?? ? . . . . .. . .  . .내가 넘 싫다. .

vector<int> sam;

void samkak(){
    int n =1;
    while(n*(n+1)/2 < 1000){
        sam.push_back(n * (n+1)/2);
        n++;
    }

}

bool tri(int total){
    for(int i=0; i< sam.size(); i++){
        for(int j=0; j< sam.size(); j++){
            for(int k=0; k<sam.size(); k++){
                if(sam[i] + sam[j] + sam[k] == total)
                return true;
            }
        }
    }

    return false;
}


int main(){

    int k;
    int n;

    cin >>k;

    samkak();

    for(int i=0; i<k; i++){

        cin >> n;

        cout << tri(n) <<"\n" ;

    }






}