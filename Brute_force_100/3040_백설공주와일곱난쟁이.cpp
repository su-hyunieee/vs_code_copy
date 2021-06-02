#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v(9);

int ans;

int main()
{

    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
        ans += v[i];
    }

    for(int i=0; i<9; i++){
        for(int j= i+1; j<9; j++){

            if(ans -  v[i]- v[j] ==100){

                for(int k =0; k<9; k++){
                    if(i!=k && j!=k) {
                        cout <<v[k] <<'\n' ;
                        
                    }
                }
                break;
            }
            
        }
    }



    return 0;
}
