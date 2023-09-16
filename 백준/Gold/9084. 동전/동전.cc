#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        vector<int> coins;
        int dp[10001]={0,};
        int num,target,money;
        cin>>num; //동전의 가지수
        for(int i=0;i<num;i++){
            cin>>money;
            coins.push_back(money);
        }
        cin>>target;
        int ans;
        dp[0]=1;
        for(auto last_coin : coins){
            for(int i = last_coin;i<=target;i++){
                dp[i] = dp[i] + dp[i-last_coin];
            }
        }
        ans = dp[target];
        cout<<ans<<'\n';

    }
}