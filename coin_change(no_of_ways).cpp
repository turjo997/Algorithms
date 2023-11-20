#include<bits/stdc++.h>
using namespace std;

int main(){

   int n,w;
   cin >> n >> w;

   vector<int> v(n);

   for(int i = 0 ; i < n ; ++i){
      cin >> v[i];
   }

   v.push_back(0);  // added 0 beginning for balancing the rows and column

   sort(v.begin() , v.end());

   int ar[n+1][w+1];

   memset(ar , 0 , sizeof(ar));


   for(int i = 0 ; i <= n  ; ++i){
      for(int j = 0 ; j <= w ; ++j){
            if(i == 0){
                ar[i][0] = 1;
            }else if(v[i] > j){
                ar[i][j] = ar[i-1][j];
            }else{
                ar[i][j] = ar[i-1][j] + ar[i][j-v[i]];
             }
      }
   }

   for(int i = 0 ; i <= n  ; ++i){
      for(int j = 0 ; j <= w ; ++j){
         cout << ar[i][j] << " ";
      }
      cout << endl;
   }


   cout << "Total number of ways are : " << ar[n][w] << endl;















   return 0;
}
