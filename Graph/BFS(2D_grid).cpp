#include<bits/stdc++.h>
using namespace std;

#define MX 1000
int row , col;

vector<vector<int>> Graph(MX , vector<int>(MX));

int visited[MX][MX];
int dis[MX][MX];

bool isValid(int x , int y){
    if(x < 0 || x >= row || y < 0 || y >= col){
        return false;
    }

    if(visited[x][y] == 1){
        return false;
    }

    return true;
}

//int dx[] = {-1,0,1,0};
//int dy[] = {0,1,0,-1};

int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

void bfs(int x , int y){
  visited[x][y] = 1;
  dis[x][y] = 0;

  queue<pair<int,int>> Q;

  Q.push({x,y});

  while(!Q.empty()){
    int curX = Q.front().first;
    int curY = Q.front().second;

    //cout << curX << " "<<curY<<endl;

    Q.pop();
      for(int i = 0 ; i < 8 ; ++i){
        if(isValid(curX + dx[i] , curY + dy[i])){
           int newX = curX + dx[i];
           int newY = curY + dy[i];
           visited[newX][newY] = 1;
           dis[newX][newY] = dis[curX][curY] + 1;
           Q.push({newX,newY});
        }
      }
  }
}


int main(){



   cin >> row >> col;

   for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
           //cin >> Graph[i][j];
        }
   }

   int srcX , srcY;
   cin >> srcX >> srcY;

   bfs(srcX ,  srcY);


   cout << "Distance : " << endl;

   for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
           cout << dis[i][j] << " ";
        }
        cout << endl;
   }


   return 0;
}

/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1 1
*/



