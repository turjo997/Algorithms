#include<bits/stdc++.h>
using namespace std;

int main(){

    int n , m;
    cin >> n >> m;

    int pt[n];
    int wt[n];

    for(int i = 0 ; i < n ; ++i){
        cin >> pt[i];
    }

    for(int i = 0 ; i < n ; ++i){
        cin >> wt[i];
    }

    int k[n][m+1];

    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
                if(i == 0 || j == 0){
                    k[i][j] = 0;
                }
                else if(wt[i] > j){
                    k[i][j] = k[i-1][j];
                }else{
                    k[i][j] = max(k[i-1][j - wt[i]] + pt[i] , k[i-1][j]);
                }

        }
    }

      for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
              cout << k[i][j] << " ";
        }

        cout << endl;
    }




    return 0;
}

/*

// 0 should be added both profit and weight
// weight should be sorted in order

5 8
0 1 2 5 6
0 2 3 4 5



*/
