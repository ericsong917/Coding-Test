#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int ans = 2000000001;  
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int left=0;
    int right = 0;
    while(right<n){
        if(arr[right] - arr[left] < m)
            right++;
        else{
            ans = min(ans , arr[right]- arr[left]);
            if(ans==m)
                break;
            left++;}
        
    }
    cout<<ans;
}