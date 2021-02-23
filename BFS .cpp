#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

vector<int> graph[MAX];

bool vis[MAX];
int dis[MAX];


void bfs(int src){

     queue<int> q;

     vis[src]=1;
     dis[src]=0;

     q.push(src);
     while(!q.empty()){

             int node=q.front();
             q.pop();

             for(int i=0;i<graph[node].size();i++){

                    int nxt=graph[node][i];
                    if(vis[nxt]==0){
                        vis[nxt]=1;
                        dis[nxt]=dis[node] + 1;
                        q.push(nxt);
                    }
             }

             cout<<node<<" ";
     }

}


int main()
{

         int nodes,edges;
         cin>>nodes;

         edges=nodes-1;


         for(int i=1;i<=edges;i++){
                int u,v;
                cin>>u>>v;
                graph[u].push_back(v);
                graph[v].push_back(u);
         }


           int src;
           cin>>src;

           bfs(src);


           for(int i=1;i<=nodes;i++){

               cout<<"Distance of "<<i<<" "<<" is : "<< dis[i]<<endl;
           }


        cout<<endl;
        cout<<endl;

        for (int i = 1; i <= nodes; i++){
        if (vis[i] == 1){
            cout << "Node " << i << " is visited." << endl;

        }
        else{
            cout << "Node " << i << " is not visited" << endl;
        }
    }



            return 0;
}


/*
7 9
1 2
1 3
1 7
2 3
3 7
2 4
4 5
3 6
5 6
1
*/
