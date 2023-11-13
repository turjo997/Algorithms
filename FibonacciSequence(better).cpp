#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll F[51];

ll fib(ll n){
   if(n<=1) return n;
   return fib(n-1) + fib(n-2);
}

ll fib1(ll n){
   if(n<=1) {
     F[n] = n;
     return n;
   }else{

      if(F[n-2] == -1){
        F[n-2] = fib1(n-2);
      }
       if(F[n-1] == -1){
        F[n-1] = fib1(n-1);
      }

      return F[n-1] + F[n-2];
   }
}


ll factorial(ll n){

 if(n == 1){
    return 1;
 }

 return n * factorial(n-1);

}

ll sumofNthnumbers(ll n){

   if(n < 2){
    return n;
   }else{
     return n + sumofNthnumbers(n-1);
   }
}

ll sumofNthoddnumbers(ll n){

   if(n == 1){
    return n;
   }else{
     return (2*n - 1) + sumofNthoddnumbers(n-1);
   }
}

ll sumofNthevennumbers(ll n){

   if(n == 0){
    return n;
   }else{
     return (2*n) + sumofNthevennumbers(n-1);
   }
}


int main()
{

    ll n ;

    cin >> n;

    cout<<fib(n)<<endl;

    for(int i = 0 ; i<51 ; ++i){
        F[i] = -1;
    }

    cout<<fib1(n)<<endl;

    for(int i = 0 ; i<51 ; ++i){
        cout << F[i] << " " << endl;
    }




    cout<<factorial(n)<<endl;

    cout << sumofNthnumbers(n)<<endl;

    cout << sumofNthoddnumbers(n)<<endl;

    cout << sumofNthevennumbers(n) << endl;


    return 0;
}
