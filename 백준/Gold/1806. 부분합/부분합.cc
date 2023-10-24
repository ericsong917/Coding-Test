#include<bits/stdc++.h>
using namespace std;
int s,n,ans=100001;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>s;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int start = 0, end=0;
    int sum = vec[0];
    int flag=0;
    while(start<=end && end<n){
        // cout<<start<<' '<<end<<' '<<sum<<'\n';
        if(sum>=s){
            ans = min(ans,end-start+1);
            sum-=vec[start];
            start++;
            flag=1;}
        else{
            end++;
            sum+=vec[end];
        }
        
    }
    if(flag==0)
        ans=0;
    cout<<ans;
}   