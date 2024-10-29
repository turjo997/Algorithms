#include<bits/stdc++.h>
using namespace std;
#define M 1000000
bool marked[M];
bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
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
    vector<int> v1;
    int n;
    cin>>n;
    sieve(n);
    for(int i=1;i<=n;i++){
     if(isPrime(i)==true) v1.push_back(i);
    }

    
  return 0;
}
