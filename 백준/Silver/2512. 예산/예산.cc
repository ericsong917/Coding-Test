#include<bits/stdc++.h>
using namespace std;
int n; //지방의 수
vector<int> budget; //각 지방의 예산
int m ; //총 예산
int tmp;
int ans=-1;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        budget.push_back(tmp);
        sum+=tmp;
    }
    cin>>m;
    sort(budget.begin(),budget.end());
    if(sum<=m){
        cout<<budget[budget.size()-1];
        return 0;
    }

    int start =0;
    int end = budget[budget.size()-1];
    int ans;
    while(start <= end){
        //상한선으로 가능한지 check.  m을 넘어가면 상한선 줄이고, m을 넘어가지 않으면 늘리기
        int mid = (start+end)/2;
        int sum=0;
        for(auto e : budget){
            if(e<=mid)
                sum+= e;
            else
                sum+= mid;
        }
        if(sum > m){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
    }
    cout<<ans;
    return 0;

}