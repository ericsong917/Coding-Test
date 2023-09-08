#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<iostream>
using namespace std;
int dp[101][101]={0,};
int dx[2]={-1,0};
int dy[2]={0,-1};
int solution(int m, int n, vector<vector<int>> puddles) {
    set<pair<int,int>> water;
    for(auto e : puddles){
        water.insert(make_pair(e[1],e[0]));
    }
    int answer = 0;
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            if(i==1 && j==1)
                continue;
            if( water.find({i,j})!=water.end())
                continue;
            int down, left, down_x, down_y, left_x, left_y;
            down_x = i-1;
            down_y = j;
            if(down_x <1 || down_y<1 || down_x>n || down_y > m)
                down=0;
            else
                down = dp[down_x][down_y];
            left_x = i;
            left_y = j-1;
            if(left_x <1 || left_y<1 || left_x>n || left_y > m)
                left=0;
            else
                left = dp[left_x][left_y];
            dp[i][j] = (down+left) %1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}