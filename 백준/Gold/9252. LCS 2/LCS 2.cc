#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<deque>
using namespace std;
int dp[1001][1001]={0};
int dx[2]={-1,0};
int dy[2]={0,-1};
int main(){
    string a;
    string b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i]==b[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else{
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[a.size()][b.size()]<<'\n';
    if(dp[a.size()][b.size()]==0)
        return 0;
    int x = a.size();
    int y = b.size();
    deque<char> s;
    while(dp[x][y]!=0){
        if(dp[x-1][y]==dp[x][y])
            x--;
        else if(dp[x][y-1]==dp[x][y])
            y--;
        else{
            // cout<<x<<' '<<y<<'\n';
            s.push_front(b[y-1]);
            x--;
            y--;
        }
    }
    for(auto e : s)
        cout<<e;
}

