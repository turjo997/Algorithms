#include<bits/stdc++.h>
using namespace std;

int main(){
   string x,y;
   cin >> x >> y;

   int m = x.size();
   int n = y.size();

   int ar[m+1][n+1];

   memset(ar , 0 , sizeof ar);

   for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(x[i-1] == y[j-1]){
                ar[i][j] = 1 + ar[i-1][j-1];
            }else{
                ar[i][j] = max(ar[i][j-1] , ar[i-1][j]);
            }
        }
   }
     for(int i = 0 ; i <= m ; ++i){
        for(int j = 0 ; j <= n ; ++j){
           cout << ar[i][j] << " ";
        }
        cout << endl;
   }


   cout << "Length of lcs is " << ar[m][n] << endl;

   string lcs="";


   int i= m,j=n;

   while(i>0 && j>0){

        if(x[i-1] == y[j-1]){
            lcs+=x[i-1];
             --i;
             --j;
        }
        else if(ar[i-1][j] > ar[i][j-1]){
            --i;
        }else{
           --j;
        }

   }


    reverse(lcs.begin(),lcs.end());

    cout << lcs << endl;



    return 0;
}


/*

abaaba
babbab

AGGTAB
GXTXAYB


*/
