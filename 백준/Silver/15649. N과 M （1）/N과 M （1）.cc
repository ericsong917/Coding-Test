#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
bool is_used[10];
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!is_used[i]){
            arr[k]=i;
            is_used[i]=true;
            func(k+1);
            is_used[i]=0;
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    func(0);
}