#include<iostream>
using namespace std;
int N,M;
int start_x, start_y, start_dir;
int er=0;
int arr[51][50];
int check_left(int x,int y, int dir){
    int x2,y2;
    int ddir;
    if(dir==0){
        x2=0,y2=-1;
        ddir=3;
    }
    else if(dir==1){
        x2=-1,y2=0;
        ddir=0;
    }
    else if(dir==2){
        x2=0,y2=1;
        ddir=1;
    }
    else{
        x2=1,y2=0;
        ddir=2;
    }
    int cor_a=x+x2;
    int cor_b=y+y2;
    if(arr[cor_a][cor_b]!=0){
        return -1;
    }
    else{
        return ddir;
    }
}
pair<int,int> go(int x,int y,int dir){
    int x2,y2;
    if(dir==0){
        x2=-1,y2=0;
    }
    else if(dir==1){
        x2=0,y2=1;
    }
    else if(dir==2){
        x2=1,y2=0;
    }
    else{
        x2=0,y2=-1;
    }
    pair<int,int> ans=make_pair(x+x2,y+y2);
    return ans;
}
pair<int,int> back(int x,int y,int dir){
    int x2,y2;
    if(dir==2){
        x2=-1,y2=0;
    }
    else if(dir==3){
        x2=0,y2=1;
    }
    else if(dir==0){
        x2=1,y2=0;
    }
    else{
        x2=0,y2=-1;
    }
    pair<int,int> ans=make_pair(x+x2,y+y2);
    return ans;
}
void dfs(int x,int y, int dir){
    if(arr[x][y]==0){
        er++;
    }
    arr[x][y]=2;
    int dir2=dir;
    int count=0;
    for(int i=0;i<4;i++){
        count++;
        int temp=dir2;
        dir2=check_left(x,y,dir2);
        if(dir2==-1){
            if(temp==0){
                temp+=3;
                dir2=temp;}
            else{
                temp--;
                dir2=temp;
            continue;}
            }
        else{
            pair<int,int> cor=go(x,y,dir2);
            dfs(cor.first,cor.second,dir2);
            return;
        }
    }
    pair<int,int> cor=back(x,y,dir2);
    if(arr[cor.first][cor.second]==1){
        cout<<er;
        return;}
    dfs(cor.first,cor.second,dir2);
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>M;
    cin>>start_x>>start_y>>start_dir;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    dfs(start_x,start_y,start_dir);


}