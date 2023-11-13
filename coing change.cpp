#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, amount;
  cin >>  n >> amount;

  vector<int> v(n);

  for(int i = 0 ; i < n ; ++i) cin >> v[i];

  sort(v.begin() , v.end());


  int dp [n][amount+5];
  memset(dp , 0 , sizeof(dp));

  for(int i = 0 ; i < n ; ++i){
    dp[i][0] = 1;
  }

  for(int i = 0 ; i < n ; ++i){
    for(int j = 1 ; j <= amount ; ++j){
       if(i == 0){
            if(j % v[i] == 0){
                dp[i][j] = 1;
            }
       }else if(v[i] > j){
          dp[i][j] = dp[i-1][j];
       }else{
          dp[i][j] = dp[i-1][j] + dp[i][j-v[i]];
       }
    }
  }


  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j <= amount ; ++j){
        cout << dp[i][j] << " ";
    }
    cout << endl;
  }



  cout << "Total ways : " << dp[n-1][amount]<<endl;



  return 0;
}



