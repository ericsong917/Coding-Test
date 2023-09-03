#include <string>
#include<iostream>
#include <vector>
#include<queue>
using namespace std;
int map[105][105]={0,};
int visited[105][105]={0,};
int dist[105][105]={0,};
int dx[4]={0,1,-1,0};
int dy[4]={-1,0,0,1};
void fill_map(vector<int>tmp){
    int start_x = 2*tmp[1];
    int start_y = 2*tmp[0]; 
    int end_x = 2*tmp[3];
    int end_y = 2*tmp[2];
    for(int i = start_x;i<=end_x;i++){
        for(int j = start_y;j<=end_y;j++){
            if(i==start_x || i==end_x || j==start_y || j==end_y){
                if(map[i][j]!=-1)
                    map[i][j]=1;
            }

            else{
                map[i][j]=-1;
            }
            }
                
        }
    }
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer;
    for(auto e :rectangle){
        fill_map(e);
    }
    queue<pair<int,int>> Q;
    Q.push({2*characterY,2*characterX});
    visited[characterY*2][characterX*2]=1;
    dist[2*characterY][2*characterX]=1;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(x==itemY*2 && y==itemX*2){
            answer = dist[x][y]/2;
            break;
        }
        for(int dir=0;dir<4;dir++){
            int ax = x + dx[dir];
            int ay = y + dy[dir];
            if(map[ax][ay]!=1)
                continue;
            if(visited[ax][ay]==1)
                continue;
            Q.push({ax,ay});
            visited[ax][ay]=1;
            dist[ax][ay]=dist[x][y]+1;
        }
    }
    return answer;
}
