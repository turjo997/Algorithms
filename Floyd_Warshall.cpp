#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define inf 99999

#define MX 1000

int nodes,edges;
ll a[MX][MX];
ll parent[MX][MX];


void reset_(){

      for(int i=1;i<=nodes;++i){
        for(int j=1;j<=edges;++j){
            if(i == j){
                a[i][j] = 0;
            }else{
               a[i][j] = inf;
            }
            parent[i][j] = i;
        }
    }
}


void min_cost_matrix(){

       for(int i=1;i<=nodes;++i){

        for(int j=1;j<=nodes;++j){

                if(a[i][j] == inf) cout<<"INF"<< "   ";
                else               cout<<a[i][j]<<"   ";
        }
        cout<<endl;
    }
}

int pathfind(int src,int destination){

    if(src == destination){
        cout<<"PATH : " <<src;
        return 0;
    }

    pathfind(src,parent[src][destination]);

    cout<<" "<<destination;

}

void floyd_warshall(){

     for(int i=1;i<=edges;++i){
        int u,v,cost;
        cin>>u>>v>>cost;
        a[u][v] = cost;
    }

    int k = 1;

     while(k<=nodes){

      for(int i=1;i<=nodes;++i){

         for(int j=1;j<=nodes;++j){

            if(a[i][k]+a[k][j] < a[i][j]){

             a[i][j] = a[i][k]+a[k][j];

            parent[i][j] = parent[k][j];
          }

        }

      }

      ++k;
    }

}



int main()
{

    int src , destination;
    cin>>nodes>>edges;

    reset_();

    floyd_warshall();

    cin>>src >> destination;


     bool ok = false;
    for (int i = 1; i <= nodes; i++){
        if (a[i][i] < 0){
            ok = true;
            break;
        }
    }

    if(ok) {
        cout<<"THE GRAPH CONTAINS NEGATIVE CYCLE"<<endl;


    }else{

        min_cost_matrix();

         cout<<endl;

        cout<<endl;


        pathfind(src,destination);

         cout<<endl;


    }




    return 0;
}
