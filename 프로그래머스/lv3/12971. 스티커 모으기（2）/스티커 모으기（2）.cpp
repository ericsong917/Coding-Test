#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
using namespace std;

int dp[100010]={0,};
int dp2[100010]={0,};

int solution(vector<int> sticker)
{
    vector<int> ans;
    //첫번째 스티커를 뜯은 경우
    dp[0]=sticker[0];
    dp[1]=dp[0];
    for(int i=2;i<sticker.size()-1;i++){
        int yes=0, no=0;
        //현재꺼 뜯
        yes = dp[i-2]+sticker[i];
        //현재꺼 안뜯
        no = dp[i-1];
        dp[i] = max(yes,no);
    }
    if(sticker.size()==1)
        ans.push_back(dp[0]);
    else
        ans.push_back(dp[sticker.size()-2]);
    
    //첫번째 스티커를 안뜯은 경우
    dp2[0]=0;
    for(int i=1;i<sticker.size();i++){
        int yes=0, no=0;
        //현재꺼 뜯
        if(i==1){
            yes = dp2[sticker.size()-1]+sticker[i];
        }
        else
            yes = dp2[i-2]+sticker[i];
        //현재꺼 안뜯
        no = dp2[i-1];
        dp2[i] = max(yes,no);    
    }
    
    ans.push_back(dp2[sticker.size()-1]);
    
    return max(ans[0],ans[1]);
}