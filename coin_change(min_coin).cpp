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

   memset(ar , 100 , sizeof(ar)); // set the array to larger numbers
   /*
   for(int i = 0 ; i <= n  ; ++i){
      for(int j = 0 ; j <= w ; ++j){
         cout << ar[i][j] << " ";
      }
      cout << endl;
   }*/

   for(int i = 0 ; i <= n  ; ++i){
      for(int j = 0 ; j <= w ; ++j){
            if(i == 0){
                ar[i][0] = 0;
            }else if(v[i] > j){
                ar[i][j] = ar[i-1][j];
            }else{
                ar[i][j] = min(ar[i-1][j], 1 + ar[i][j-v[i]]);
             }
      }
   }

   for(int i = 1 ; i <= n  ; ++i){
      for(int j = 0 ; j <= w ; ++j){
         cout << ar[i][j] << " ";
      }
      cout << endl;
   }

   cout << endl;
   cout << "Minimum coins needed are : " << ar[n][w] << endl;

   // The coins that are selected

   int i = n , j = w;

   while(i > 0 && j > 0){
    if(ar[i][j] != ar[i-1][j]){
        cout << v[i] << " ";
        j = j - v[i];

    }else{
       --i;
    }
   }


   return 0;
}

