#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[10001]={0,};
    fill(&dp[0],&dp[10000]+1,100001);
    int n,k; //n가지 종류의 동전, 합이 k원
    cin>>n>>k;
    vector<int> nums;
    while(n--){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    } 
    dp[0]=1;
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(auto e : nums){
        for(int i=e;i<=k;i++){
            if(i-e==0){
                dp[i]=1;
                continue;
            }
            int cmp_a = dp[i-e] + dp[e];
            dp[i] = min(dp[i],cmp_a);
        }
    }
    if(dp[k]==100001)
        cout<<-1;
    else
        cout<<dp[k];
}