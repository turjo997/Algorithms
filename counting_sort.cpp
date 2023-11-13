#include<bits/stdc++.h>
using namespace std;

int main(){

   int n;
   cin >> n;

   int ar[n];

   int mx = -1;
   for(int i = 0 ; i < n ; ++i){
     cin >> ar[i];
     mx = max(mx , ar[i]);
   }

   int cnt[mx+1];

   memset(cnt , 0 , sizeof(cnt));

   for(int i = 0 ; i < n ; ++i){
      cnt[ar[i]]++;
   }

   for(int i = 1 ; i <= mx ; ++i){
      cnt[i] += cnt[i-1];
   }

   for(int i = 0 ; i <= mx ; ++i){
    cout << cnt[i] << " ";
   }

   cout << endl;



   int b[n];
   memset(b , 0 , sizeof(b));

   for(int i = n-1 ; i >= 0 ; --i){
    --cnt[ar[i]];
    b[cnt[ar[i]]] = ar[i];
   }

   for(int i = 0 ; i < n ; ++i){
      cout << b[i] << " ";
   }

   cout << endl;


}
