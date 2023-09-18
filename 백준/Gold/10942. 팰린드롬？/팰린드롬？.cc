#include<iostream>
#include<vector>
using namespace std;
int n,m,s,e;
int dp[2001][2001]={0,};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    int arr[2001];
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        arr[i]=num;
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
        if(i+1<=2000 && arr[i+1]==arr[i])
            dp[i][i+1]=1;
    }
    for(int i=n-2 ; i>=1 ; i--){
        for(int j=n; j>=i+2; j--){
            if(dp[i+1][j-1]==1 && (arr[i]==arr[j]) )
                dp[i][j]=1;
        }
    }
    cin>>m;
    while(m--){

        cin>>s>>e;
        cout<<dp[s][e]<<'\n';
    }
}