#include<bits/stdc++.h>
using namespace std;
int n,c;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>c;
    vector<int> house(n);
    for(int i=0;i<n;i++){
        cin>>house[i];
    }
    sort(house.begin(),house.end());
    int start=1;
    int end = house[house.size()-1] - house[0];
    int ans=0;
    while(start<=end){
        int cnt=1; //설치할 수 있는 공유기의 개수
        int mid = (start + end) /2; // 공유기간 거리
        int now = house[0];
        for(int i=1;i<n;i++){
            if( house[i] - now >= mid ){
                now = house[i];
                cnt++;
            }
        }
        if(cnt>=c){
            ans = max(ans,mid);
            start = mid+1;
        }
        else
            end = mid-1;
    }


    cout<<ans;
}