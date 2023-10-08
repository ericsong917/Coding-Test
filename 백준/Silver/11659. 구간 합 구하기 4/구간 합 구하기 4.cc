#include<iostream>
#include<vector>
using namespace std;
int n,m,s,e;
vector<int> arr;
vector<int> dp;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    int tmp;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        arr.push_back(tmp);
        dp.push_back(tmp+sum);
        sum+=tmp;
    }



    while(m--){
        cin>>s>>e;
        s--; e--;
        if(s==0)
            cout<<dp[e]<<'\n';
        else{
            cout<<dp[e]-dp[s-1]<<'\n';
        }
    }
}