#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int T;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main(){
    cin.tie();
    ios::sync_with_stdio(0);
    cin>>T;
    for(int i=0;i<T;i++){
        queue<pair<int,int>> q;
        queue<pair<int,int>> Q;
        int board[50][50];
        int visit[50][50];
        int M,N,K;
        int r,c;
        int ans=0;
        cin>>M>>N>>K;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                board[i][j]=0;
                visit[i][j]=0;
            }
        }
        for(int i=0;i<K;i++){
            cin>>r>>c;
            board[r][c]=1;
            q.push({r,c});
        }
        while(!q.empty()){
            auto cur=q.front(); q.pop();
            if(visit[cur.X][cur.Y]==1) continue;
            ans++;
            Q.push(cur);
            visit[cur.X][cur.Y]=1;
            while(!Q.empty()){
                auto cur=Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=dx[dir]+cur.X;
                    int ny=dy[dir]+cur.Y;
                    if(nx<0||ny<0||nx>=50||ny>=50) continue;
                    if(visit[nx][ny]==1 || board[nx][ny]==0) continue;
                    visit[nx][ny]=1;
                    Q.push({nx,ny});
                }
            }
        }
        cout<<ans<<"\n";

    }
    }