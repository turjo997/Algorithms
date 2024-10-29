#include<bits/stdc++.h>
using namespace std;


void merge(int ar[] , int left , int mid , int right){

    int size_left = mid - left + 1;
    int size_right = right -mid;
    int A[size_left];
    int B[size_right];

    for(int i = 0 ; i < size_left ; ++i){
        A[i] = ar[left+i];
    }

    for(int i = 0 ; i < size_right ; ++i){
        B[i] = ar[i+mid+1];
    }

    int i = 0, j = 0, k = left;

    while (i < size_left && j < size_right) {
        if (A[i] <= B[j]) {
            ar[k++] = A[i++];
        } else {
            ar[k++] = B[j++];
        }
    }

    while (i < size_left) {
        ar[k++] = A[i++];
    }

    while (j < size_right) {
        ar[k++] = B[j++];
    }
}
void merge_sort(int ar[] , int left , int right){

    if(left >= right){
        return;
    }

    int mid = left + (right - left)/2;

    merge_sort(ar , left , mid);

    merge_sort(ar , mid + 1 , right);

    merge(ar , left , mid , right);
}

int main(){

   int n;
   cin >> n;

   int ar[n];

   for(int i = 0 ; i < n ; ++i){
       cin >> ar[i];
   }

   int left = 0;
   int right = n;
   merge_sort(ar , left , right);


    for(int i = 0 ; i < n ; ++i){
       cout << ar[i] << " ";
   }

   return 0;
}


/*



10
2 3 1 5 4 10 8 9 7 6



*/
