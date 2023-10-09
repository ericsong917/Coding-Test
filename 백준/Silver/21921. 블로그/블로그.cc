#include<bits/stdc++.h>
using namespace std;
int x,n;
vector<int> arr;
int dp[250001]={0,};
int dp2[250001]={0,};
int tmp;
int mx=0;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(i==0)
            dp[i]=tmp;
        else{
            dp[i] = tmp+dp[i-1];
        }
        if(tmp > mx)
            mx=tmp;
    }
    
    if(mx==0){
        cout<<"SAD";
        return 0;
    }
    mx=0;
    for(int i=0;i<=n-x;i++){
        if(i==0)
            dp2[i] = dp[i+x-1];
        else
            dp2[i] = dp[i+x-1] - dp[i-1];
        mx = max(dp2[i],mx);
    }
    cout<<mx<<'\n';
    int ans=0;
    for(int i=0;i<=n-x;i++){
        if(dp2[i]==mx){
            ans++;
        }
    }
    cout<<ans;
    return 0;



}