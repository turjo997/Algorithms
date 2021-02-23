#include<bits/stdc++.h>
using namespace std;

#define MAX 1010
vector <int> graph[MAX];
bool visited[MAX];


bool dfs(int source,int par){
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++){
        int next = graph[source][i];

             if (visited[next] == 0){
                if(dfs(next,source)==true){
                    return true;
                }
             }

             else{
                if(next!=par){
                    return true;
                }

             }
    }
    return false;
}

int main()
{
    while(true){
    int nodes, edges;
    cin >> nodes;

    if(nodes==0)break;

    cin >> edges;

    for(int i=0;i<nodes+1;i++){
            visited[i]=0;
            graph[i].clear();
    }
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(dfs(0,0)==true){
        cout<<"NOT BICOLORABLE."<<endl;
    }else{
      cout<<"BICOLORABLE."<<endl;
    }


    }
    return 0;
}


