#include<bits/stdc++.h>
using namespace std;
#define M 1000000
#define ll long long
int List[M];
int listSize;
vector<ll> prime,primes;
bool marked[M];
bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
}
void prime_factorize(int n)
{
    int sqrn= int ( sqrt(n) );
      listSize = 0;
    for( int i = 0; prime[i] * prime[i]<= n && i<=prime.size(); i++ ) {
         if( n % prime[i] == 0 ) {
            while( n % prime[i] == 0 ) {
                n /= prime[i];
               // primes.push_back(prime[i]);
                List[listSize] = prime[i];
                listSize++;
            }
        }
    }
    if( n > 1 ) {
        primes.push_back(n);
        List[listSize] = n;
        listSize++;
    }
}
void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) {
      for (int j = i * i; j <= n; j += i + i){
        marked[j] = true;
      }
    }
  }
}
int main()
{
    while(1){
    int n,x;
    cin>>n;

    if(n==0)break;
    x=n;
    if(n<0) n=n*-1;
    sieve(n);
    for(int i=1;i<=n;i++){
     if(isPrime(i)==true) prime.push_back(i);
    }
        prime_factorize(n);

       if(x>0){
            cout<<x<<" "<<"="<<" ";
            cout<<1<<" "<<"x"<<" ";

         for( int i = 0; i < listSize-1; i++ ){
                 cout<<List[i]<<" "<<"x"<<" ";
         }
            cout<<List[listSize-1];

         /*
             for( int i = 0; i < primes.size()-1; i++ ){
                 cout<<primes[i]<<" "<<"x"<<" ";
         }
            cout<<primes[primes.size()-1];
          */

       }
        else{
                 cout<<x<<" "<<"="<<" ";
                     cout<<-1<<" "<<"x"<<" ";
                     /*
                     for( int i = 0; i < primes.size()-1; i++ ){
                 cout<<primes[i]<<" "<<"x"<<" ";
         }
            cout<<primes[primes.size()-1];
         */
          for( int i = 0; i < listSize-1; i++ ){
                 cout<<List[i]<<" "<<"x"<<" ";
         }
            cout<<List[listSize-1];
        }
        cout<<endl;
    }

  return 0;
}
