#include <string>
#include <vector>
#include <math.h>
using namespace std;
int dp[501][501]={0,};
int solution(vector<vector<int>> triangle) {
    int height = triangle.size()-1;
    for(int i=0;i<triangle[height].size();i++){
        dp[height][i]=triangle[height][i];
    }
    
    for(int i=height-1;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            dp[i][j]= triangle[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    int answer = dp[0][0];
    
    
    return answer;
}