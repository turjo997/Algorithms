#include<bits/stdc++.h>
using namespace std;

#define MX 100

int parent[MX];
int Size[MX];
int Rank[MX];
int nodes , edges;

void makeset(int i){
   parent[i] = i;
   Size[i] = 1;
   Rank[i] = 0;
}

void init(){
   for(int i = 1 ; i <= nodes ; ++i){
        makeset(i);
   }
}

int Find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u]);
}

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


bool isFriend(int u , int v){

    int p = Find(u);
    int q = Find(v);

    return (p == q);
}


int main(){

     cin >> nodes >> edges;

     vector<vector<int>> G;
     init();

    for(int i=1;i<=edges;++i){
        int u,v, wei;
        cin >> u >> v >> wei;
        G.push_back({wei , u , v});
    }

    sort(G.begin() , G.end());

    int cost = 0;
     for(auto i : G){
         int w = i[0];
         int u = i[1];
         int v = i[2];

         int x = Find(u);
         int y = Find(v);

         if(x == y){
            continue;
         }

         cout << u << " " << v << endl;

         cost += w;

         Union(x , y);
    }



    for (int i = 1; i <= nodes; i++){
       cout << "parent of " << i << " is " << parent[i] << endl;
    }


    cout << "Krushkal cost is : " << cost << endl;


   return 0;
}

/*

6 9
1 2 5
1 3 3
2 3 6
2 4 2
2 5 4
1 6 7
3 6 8
4 5 2
3 4 3



*/
