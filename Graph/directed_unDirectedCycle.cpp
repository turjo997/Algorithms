#include<bits/stdc++.h>
using namespace std;

#define White 0
#define Gray 1
#define black 2

int visited[100];
vector<int> G[100];
bool cycle;
bool cycle2;

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = Gray;

    while(!q.empty()){
      int node = q.front();
      q.pop();

      visited[node] = black;


      for(int i = 0 ; i < G[node].size() ; ++i){
        int nxt = G[node][i];
        if(visited[nxt] == White){
            visited[nxt] = Gray;
            q.push(nxt);
        }else if(visited[nxt] == Gray){
              cycle = true;
              return;
        }
      }



    }
}



void dfs(int src){

    stack<int> s;
    s.push(src);
    visited[src] = Gray;

    while(!s.empty()){
        int node = s.top();
        s.pop();
        visited[src] = black;
        for(int i = 0 ; i < G[node].size() ; ++i){
           int nxt = G[node][i];
           if(visited[nxt] == White){
               visited[nxt] = Gray;
               s.push(nxt);
           }else if(visited[nxt] == Gray){
               cycle2 = true;
               return;
           }
        }
    }

}


int main(){

    cycle = cycle2 = false;

    int nodes,edges, src;

    cin >> nodes >> edges >> src;

    /*

    // for bfs


    for(int i = 1 ; i <= edges ; ++i){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bfs(src);

    if(cycle){
        cout << "The graph contains cycle"<<endl;
    }else{
        cout << "does not contain cycle"<<endl;
    }


 */

 // For DFS


    for(int i = 1 ; i <= edges ; ++i){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    dfs(src);

    if(cycle2){
        cout << "The graph contains cycle"<<endl;
    }else{
        cout << "does not contain cycle"<<endl;
    }

   return 0;
}
