#include<iostream>
#include<vector>
using namespace std;
int n;
int ans=0;
int weight[10]={0,};
int durability[10]={0,};
void backtrack(int depth){
    if(depth==n){
        int count=0;
        for(int i=0;i<n;i++){
            if(durability[i]<=0)
                count++;
        }
        if(count>ans)
            ans=count;
        return;
    }
    else if(durability[depth]<=0)
        backtrack(depth+1);
    else{
        for(int i=0;i<n;i++){
            if(i==depth)
                continue;
            else{
                if(durability[i]<=0)
                    backtrack(depth+1);
                else{
                    durability[depth]-=weight[i];
                    durability[i]-=weight[depth];
                    backtrack(depth+1);
                    durability[depth]+=weight[i];
                    durability[i]+=weight[depth];
                }
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        weight[i]=b;
        durability[i]=a;
    }
    backtrack(0);
    cout<<ans;
}
