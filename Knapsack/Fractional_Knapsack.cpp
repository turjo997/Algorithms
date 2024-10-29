#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    double w;
    cin >> w;

    vector<double> profit(n) , weight(n);
    vector<pair<double,int>> Ratio;

    for(int i = 0 ; i < n ; ++i){
        cin >> profit[i];
    }

    for(int i = 0 ; i < n ; ++i){
        cin >> weight[i];
    }

    for(int i = 0; i < n ; ++i){
        Ratio.push_back(make_pair(profit[i]/weight[i],i));
    }

    sort(Ratio.rbegin() , Ratio.rend());


    double maxprofit = 0.0;
    double remainingWeight = w;

    for(int i = 0; i < n ; ++i){
        
       if(remainingWeight > 0){

            double x = min(remainingWeight , weight[Ratio[i].second]);
            remainingWeight -= x;
            maxprofit += profit[Ratio[i].second] * (x/weight[Ratio[i].second]);

       } else{
          break;
       }
    }

    cout << maxprofit << endl;




    return 0;
}

/*

7 15
5 10 15 7 8 9 4
1 3 5 4 1 3 2

*/
