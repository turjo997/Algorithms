#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll pow1(ll x , ll n){

   if(n == 0) return 1;

   return x * pow(x,n-1);

}
ll pow2(ll x , ll n){

  if(n == 0) return 1;

  if(n%2 == 0){
      ll y = pow2(x , n/2);
      return y * y;
  }
  else{
     return x * pow2(x , n-1);
  }

}


ll mod (ll x , ll n , ll M){

     if(n == 0) return 1;

     if(n%2 == 0){

        ll y = mod(x , n/2 , M);

        return ( y * y ) % M ;
     }else{

        return ( (x % M ) * (mod(x , n-1 , M)) ) % M;

     }


}

int recursivePower(ll x,ll n)
{
    if(n==0)
        return 1;
    return x*recursivePower(x,n-1);
}

int main()
{

     ll x , n , M;

     cin >> x >> n >> M;

     cout<<pow1(x , n)<<endl;


     cout<<pow2(x , n) <<endl;

     cout<<mod(x , n , M) <<endl;
  
     cout<<recursivePower(x,n);




    return 0;
}
