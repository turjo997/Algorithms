#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MX 1005

int parent[MX];

int nodes;
int edges;

struct node{
   int val;
   int cost;
};

vector<node> G[MX];

int cost_[MX];
int visited[MX];

void reset_(){
      for(int i=1;i<=nodes;++i){
        G[i].clear();
        cost_[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
      }
}

class cmp{

public:
bool operator()(node A, node B){

        if(A.cost>B.cost) return true;
        return false;
}
};


void display(int src){

     cout<<"Edge \tWeight\n";
    for (int i = 1; i <= nodes; i++) {
        if(i !=src)
        cout<<parent[i]<<" - "<<i<<" \t"<<cost_[i]<<" \n";

    }
}


int prim(int src){

     cost_[src]  = 0;
     priority_queue<node , vector<node> , cmp> pq;

     pq.push({src,0});

     int mst_cost = 0;


   while(!pq.empty()){

       node cur = pq.top();

       pq.pop();

       int val = cur.val;
       int cost = cur.cost;

       if(visited[val] == 1) continue;

       visited[val]  = 1;

       mst_cost += cost;


       for(int i=0;i<G[val].size();++i){
         int nxt = G[val][i].val;
         int nxt_cost = G[val][i].cost;

         if(visited[nxt] == 1) continue;

         if(nxt_cost < cost_[nxt]){
            pq.push({nxt , nxt_cost});
            cost_[nxt] = nxt_cost;
            parent[nxt] = val;
         }

       }

   }

   return mst_cost;

}

int main()
{

     cin >> nodes >> edges;

     reset_();

    for(int i=1;i<=edges;++i){
        int u,v, wei;
        cin >> u >> v >> wei;
        G[u].push_back({v,wei});
        G[v].push_back({u,wei});
    }

    int src;
    cin >> src;
    int res = prim(src);

    cout<<endl;


    cout<<"PRIM'S MINIMUM SPANNING TREE COST IS  :: "<<res<<endl;

    cout<<endl;

    display(src);





    return 0;
}
