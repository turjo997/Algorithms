#include<bits/stdc++.h>
using namespace std;

#define MX 1005
#define INF 1000000000

struct node{
    int val;
    int cost;
};


vector<node> G[MX];

bool vis[MX];
int dis[MX];
int parent[MX];

int nodes,edges;
int src;

void clear_(){
    for (int i = 0; i < MX; i++){
        G[i].clear();
        vis[i] = 0;
        dis[i] = INF;
        parent[i] = i;
    }
}

class compare{

public:
      bool operator() (node &First, node &Second){

        if(First.cost>Second.cost) return true;
        return false;

      }
};


void display(int par[]){

    for(int i =1 ;i <= nodes ;i++){
       int temp = par[i] ;
       if(dis[i] == INF){
         cout<<"Node: " << i << "   Distance: INF "<<" PATH : NO PATH"<<endl;
         continue;
       }

      cout << "Node: " << i << "   Distance: ";
      cout<<dis[i]<<"  ";
      cout<<"  PATH :  ";
      cout<<i << " --- ";
       while(temp!=src)
       {
           cout<< temp << " -- " ;
           temp = par[temp] ;
       }
          cout<<src;
       cout<<endl;

   }
}

void dijkstra(int src){

      priority_queue<node,vector<node>, compare> pq;

      pq.push({src,0});

      while(!pq.empty()){
        node cur=pq.top();
        pq.pop();

        int val=cur.val;
        int cost=cur.cost;

        if(vis[val]==1)continue;

        dis[val]=cost;
        vis[val]=1;

        for(int i=0; i< G[val].size();i++){
            int nxt_node=G[val][i].val;
            int nxt_edge_cost=G[val][i].cost;

            if(vis[nxt_node]==0){
                parent[nxt_node] = val;
                pq.push({nxt_node,cost+nxt_edge_cost});
            }

        }


      }


   display(parent);

}


int main()
{

   clear_();

    cin>>nodes>>edges;

    for(int i=1;i<=edges;i++){
        int u,v,edge_cost;
        cin>>u>>v>>edge_cost;
        G[u].push_back({v,edge_cost});
    }

    cin>>src;

    dijkstra(src);



    return 0;
}
