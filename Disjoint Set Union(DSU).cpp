#include<bits/stdc++.h>
using namespace std;

#define MX 100

int parent[MX];
int Size[MX];
int Rank[MX];

void makeset(int i){
   parent[i] = i;
   Size[i] = 1;
   Rank[i] = 0;
}

void init(){
   for(int i = 1 ; i <= 8 ; ++i){
        makeset(i);
   }
}

int Find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u]);
}
/*

// normal union

void Union(int u , int v){

    int p = Find(u);
    int q = Find(v);

    if(p != q){
        parent[q] = p;
    }
}

*/


// union by size
void Union(int u , int v){

    int p = Find(u);
    int q = Find(v);

    if(p != q){
        if(Size[p] < Size[q]){
            swap(p,q);
        }
        parent[q] = p;
        Size[p] += Size[q];
    }
}

/*
// union by rank
void Union(int u , int v){

    int p = Find(u);
    int q = Find(v);

    if(p != q){
        if(Rank[p] < Rank[q]){
            swap(p,q);
        }
    parent[q] = p;

    if(Rank[p] == Rank[q]){
        Rank[p] += 1;
    }
    }
}
*/

bool isFriend(int u , int v){

    int p = Find(u);
    int q = Find(v);

    return (p == q);
}
int main(){
      init();

    for (int i = 1; i <= 8; i++){
       cout << "parent of " << i << " is " << parent[i] << endl;
    }

    cout << Find(1)<< " " << Find(3) << endl;
    Union(1, 2);
    Union(2, 3);
    Union(3, 4);
    Union(4, 5);
    Union(5, 6);
    Union(6, 7);
    Union(7, 8);

    cout << Find(1)<< " " << Find(3) << endl;


    if (isFriend(4, 7)){
        cout << "They are friends!" << endl;
    }
    else cout << "They are not friends!" << endl;


   return 0;
}
