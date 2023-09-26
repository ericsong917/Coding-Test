#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int m,n; //조카수 과자수
    vector<int> snacks;
    cin>>m>>n;
    while(n--){
        int tmp;
        cin>>tmp;
        snacks.push_back(tmp);
    }

    int low,high,mid;
    int ans=-1;
    low=1;
    high=1000000000;
    while(low<=high){
        mid = (low+high)/2;
        int count=0;
        for(auto e : snacks){
            count+=(e/mid);
        }
        if(count >= m){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans<=0)
        ans=0;
    cout<<ans;
}