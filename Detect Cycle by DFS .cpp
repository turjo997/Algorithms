#include<bits/stdc++.h>
using namespace std;

vector <int> graph[100];
bool visited[100];


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
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(dfs(1,1)==true){
        cout<<"The Graph Contains Cycle"<<endl;
    }else{
      cout<<"The Graph doesn't contain any Cycle"<<endl;
    }


   
    return 0;
}

