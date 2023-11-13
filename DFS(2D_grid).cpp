#include<bits/stdc++.h>
using namespace std;

#define MX 1000
int row , col;

vector<vector<int>> Graph(MX , vector<int>(MX));

bool visited[MX][MX];

bool isValid(int x , int y){
    if(x < 0 || x >= row || y < 0 || y >= col){
        return false;
    }

    if(visited[x][y] == true){
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

    /*
    if(isValid(x-1 , y)){
       dfs(x-1 , y);
    }

    if(isValid(x , y+1)){
       dfs(x , y+1);
    }

    if(isValid(x+1 , y)){
       dfs(x+1 , y);
    }

    if(isValid(x , y-1)){
       dfs(x , y-1);
    }
    */
}


int main(){



   cin >> row >> col;

   for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
           cin >> Graph[i][j];
        }
   }


   dfs(0 , 0);

   cout << Graph[0][2] << endl;


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
3 3
-1 2 3
0 9 8
1 0 1
*/


