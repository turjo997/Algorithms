#include<bits/stdc++.h>
using namespace std;

#define MX 1000
int row , col;

vector<vector<int>> Graph(MX , vector<int>(MX));

bool visited[MX][MX];

bool isValid(int x , int y){
    if(x < 0 || x > row-1 || y < 0 || y > col-1){
        return false;
    }

    if(visited[x][y] == true || Graph[x][y] == 0){
        return false;
    }

    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x , int y){
    visited[x][y] = 1;

    cout << x << " " << y << endl;

    for(int i = 0 ; i < 4 ; ++i){
        if(isValid(x + dx[i] , y + dy[i])){
           dfs(x + dx[i] , y + dy[i]);
        }
    }
}


int main(){


   cin >> row >> col;

   for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
           cin >> Graph[i][j];
        }
   }


   int dfsCall = 0;

   for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
           if(Graph[i][j] == 1 && visited[i][j] == 0){
                dfs(i , j);
                dfsCall++;
          }
        }
   }

   cout << "Total connected component : " << dfsCall << endl;

   /*
   for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
           cout << Graph[i][j] << " ";
        }
        cout << endl;
   }*/





   return 0;
}

/*
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0


4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
*/



