#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
char board [6561][6261];
void recurse(pair<int,int> start,int N){
    if(N==3){
        for(int i=start.X;i<start.X+3;i++){
            for(int j=start.Y;j<start.Y+3;j++){
                if(i==start.X+1 && j==start.Y+1){
                    board[i][j]=' ';
                    continue;}
                board[i][j]='*';}}}
    else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1&&j==1){
                    continue;
                } 
                recurse({start.X+i*N/3,start.Y+j*N/3},N/3);
            }
        }
    }                
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)    {
        for(int j=0;j<n;j++){
            board[i][j]=' ';
            }
        }
        
    recurse({0,0},n);
    for(int i=0;i<n;i++)    {
        for(int j=0;j<n;j++){
            cout<<board[i][j];
            if(j==n-1){ cout<<'\n';}
        }
    }
}