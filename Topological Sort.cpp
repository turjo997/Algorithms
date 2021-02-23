#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
vector <int> graph[MAX];
bool visited[MAX];

vector<int> res;

void dfs(int source){
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++){
        int next = graph[source][i];
        if (visited[next] == 0)
            dfs(next);
    }

    res.push_back(source);

}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i<= nodes; i++){
        if (visited[i] == 0){
            dfs(i);
        }

    }

     for(int i=res.size()-1;i>=0;i--){

           cout<<res[i]<<" ";
     }


    return 0;
}

/*
5 4
1 2
3 2
2 4
2 5
*/
