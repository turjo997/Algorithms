#include<bits/stdc++.h>
using namespace std;

#define MX 1000
vector<int> Graph[MX];

bool visited[5];

void dfs(int src){
  visited[src] = 1;
  for(int i = 0 ; i < Graph[src].size() ; ++i){
      int next = Graph[src][i];
      if(visited[next] == 0){
         dfs(next);
      }
  }

  //cout << src << endl;

}


int main(){

   int nodes , edges;

   cin >> nodes >> edges;

   for(int i = 0 ; i < edges ; ++i){
        int u , v ;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
   }


   int dfsCall = 0;

       for(int i = 0 ; i < nodes ; ++i){
          if(visited[i] == 0){
                dfs(i);
                dfsCall++;
          }
       }



     for(int i = 0 ; i < nodes ; ++i){
      if(visited[i] == 1){
        cout << "Node " << i << " is visited"<<endl;
       }
      else{
        cout << "Node " << i << " is not visited"<<endl;
      }
    }

    cout << dfsCall << endl;



   return 0;
}

/*
5 4
0 1
1 2
1 3
3 4


5 5
0 1
1 3
2 4
2 5
5 4
*/


