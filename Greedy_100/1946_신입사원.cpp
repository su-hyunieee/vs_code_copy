
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> emp[1000001];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt;

    cin>> cnt;


    for(int i=0; i<cnt; i++){

        cin >> n;

        for(int i=0; i<n; i++)
            cin >> emp[i].first >> emp[i].second;
        

        sort(emp, emp+ n);

       // 이게 젤 높은 사람 
        cout<<emp[0].first <<" " <<emp[0].second<<endl;
        int ret=1 ;
        int second_rank = emp[0].second;

        for(int i=1; i<n; i++)
        {
            //면접 등수라도 높아야 채용 됨 
            if(emp[i].second < second_rank)
            {

                ret ++ ;

                second_rank = emp[i].second;
            }

        }

        printf("%d\n", ret);


    }
    return 0;
}