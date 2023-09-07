#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int visited[10]={0,};
int ans=0;
void backtrack(int now_piro, vector<vector<int>>dungeons,int len){
    if(len>ans)
        ans=len;
    
    for(int i=0;i<dungeons.size();i++){
        if(visited[i]==1)
            continue;
        else{
            if(now_piro < dungeons[i][0])
                continue;
            visited[i]=1;
            backtrack(now_piro-dungeons[i][1],dungeons,len+1);
            visited[i]=0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    backtrack(k,dungeons,0);
    return ans;
}