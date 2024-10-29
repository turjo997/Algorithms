#include<bits/stdc++.h>
using namespace std;

int iterative_bsearch(int low , int high , vector<int> v , int key){

     while(low<=high){

     int mid=(low+high)/2;

     if(v[mid]<key){
         low=mid+1;
     }
     else if(v[mid]>key){
         high=mid-1;
     }
     else{
         return mid;
     }
   }
   return -1;

}

int recursive_bsearch(int low , int high , vector<int> v ,int key){

    if(low == high){

          if(v[low] == key)
                return low;
          else

              return -1;
          }

    else{
         int mid = (low + high) / 2;

         if(key == v[mid])
                return mid;

         if(key < v[mid])
            return recursive_bsearch(low , mid - 1 , v , key);

          else

            return recursive_bsearch(mid + 1, high , v , key);

      }
}

int main(){

       int  n ; cin >> n;

       vector<int> v(n);


       for(int i = 0 ; i<n ; ++i){
          cin >> v[i];
       }

       int key ; cin >> key;


       sort(v.begin() , v.end());

       cout<< iterative_bsearch(0,n-1,v,key)<<endl;
       cout<< recursive_bsearch(0,n-1,v,key);






   return 0;
}
