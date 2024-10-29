#include<bits/stdc++.h>
using namespace std;

int rec_b_search(vector<int> v , int l , int h , int tar){

    if(l == h){
        if(v[l] == tar){
            return l;
        }else{
            return -1;
        }

    }else{

        int mid = (l+h)/2;

        if(v[mid] == tar){
            return mid;
        }
        if(v[mid] > tar){
          return rec_b_search(v , l , mid-1 , tar);
        }else{
          return rec_b_search(v , mid+1 , h , tar);
        }
    }

}



int main(){
   int n , target;
   cin >> n >> target;

   vector <int> v(n);

   for(int i = 0 ; i < n ; ++i){
      cin >> v[i];
   }

   sort(v.begin() , v.end());

   for(int i = 0 ; i < n ;  ++i){
      cout << v[i] << " ";
   }
   cout << endl;

   int l = 0;
   int r = n-1;
   int ok = 0;

   while(l <= r){
        int mid = (l+r)/2;

        if(v[mid] == target){
            ok = 1;
            break;
        }

        else if(v[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }

   }


   if(ok == 1){
    cout << "Data Found"<<endl;
   }else{
    cout << "Data not found" << endl;
   }


   cout<<rec_b_search(v , 0 , n-1 , target) <<endl;

}

