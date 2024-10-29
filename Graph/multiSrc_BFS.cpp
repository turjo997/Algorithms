#include<bits/stdc++.h>
using namespace std;

#define MX 1000
vector<int> Graph[MX];

bool visited[MX];
int dis[MX];

void bfs(vector<int> sources){
  queue<int> Q;
  for(int i = 0 ; i < sources.size() ; ++i){
      visited[sources[i]] = 1;
      dis[sources[i]] = 0;
      Q.push(sources[i]);
  }

  while(!Q.empty()){
    int node = Q.front();
    Q.pop();
      for(int i = 0 ; i < Graph[node].size() ; ++i){
          int next = Graph[node][i];
          if(visited[next] == 0){
             visited[next] = 1;
             dis[next] = dis[node] + 1;
             Q.push(next);
          }
      }
  }
}

int main(){

   int nodes , edges;

   cin >> nodes >> edges;

   for(int i = 1 ; i <= edges ; ++i){
        int u , v ;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
   }

    int soures;
    cin>>soures;

    vector<int> list_src(soures);

    for(int i = 0 ; i < soures ; ++i){
        cin >> list_src[i];
    }

    bfs(list_src);


    for(int i=1;i<=nodes;i++){
      cout<<"Distance of "<<i<<" "<<" is : "<< dis[i]<<endl;
    }
    cout<<endl;
    cout<<endl;

    for(int i = 1 ; i <= nodes ; ++i){
      if(visited[i] == 1){
        cout << "Node " << i << " is visited"<<endl;
       }
      else{
        cout << "Node " << i << " is not visited"<<endl;
      }
    }
   return 0;
}

/*
10 13
1 2
1 3
2 4
3 4
1 5
3 6
5 6
6 7
5 10
6 10
9 1
7 9
8 9
3
1 7 10
*/



