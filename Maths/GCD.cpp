#include<bits/stdc++.h>
using namespace std;

int gcd1(int a , int b){

    while(b != 0){
        int rem = a % b ;
        a = b;
        b = rem;
    }

    return a;
}

int gcd2(int a , int b){

    if(b == 0){
        return a;
    }

    int rem = a % b ;
    a = b;
    b = rem;
    return gcd2(a , b);
}


int lcm(int a , int b , int gcd){

    return (a*b)/gcd;
}
int main(){

  int a , b , c , d;
  cin >> a >> b;

  c = a , d = b;

  cout << gcd1(a , b) << endl;
  cout << lcm(a, b , gcd1(a , b)) << endl;
  cout << gcd2(c , d) << endl;

  return 0;
}



