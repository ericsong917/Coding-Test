#include<deque>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
int ans=0;
int n,m,k;
int arr[30][30];
int dice[7]={0,1,2,3,4,5,6};
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int x=1; //현재 주사위 x좌표
int y=1;  //현재 주사위 y 좌표
int dir=1;  //현재 주사위 방향
void move(){  //이동후-> 점수획득 ->  방향전환  동서남북 1234
    int temp;
    int temp_x=x;
    int temp_y=y;
    temp_x+=dx[dir];
    temp_y+=dy[dir];
    if(temp_x<1 || temp_y<1 || temp_x>n || temp_y>m){
        if(dir==1 || dir==2)
            dir = 3 - dir;
        else
            dir= 7 - dir;
    }
    x+=dx[dir];
    y+=dy[dir];
    int dice2[7]={0,};
    if(dir==1){
        dice2[1]=dice[4];
        dice2[2]=dice[2];
        dice2[3]=dice[1];
        dice2[4]=dice[6];
        dice2[5]=dice[5];
        dice2[6]=dice[3];
        for(int i=1;i<=6;i++){
            dice[i]=dice2[i];
        }
    }
    else if(dir==2){
        dice2[1]=dice[3];
        dice2[2]=dice[2];
        dice2[3]=dice[6];
        dice2[4]=dice[1];
        dice2[5]=dice[5];
        dice2[6]=dice[4];
        for(int i=1;i<=6;i++){
            dice[i]=dice2[i];
        }
    }
    else if(dir==3){
        dice2[1]=dice[2];
        dice2[2]=dice[6];
        dice2[3]=dice[3];
        dice2[4]=dice[4];
        dice2[5]=dice[1];
        dice2[6]=dice[5];
        for(int i=1;i<=6;i++){
            dice[i]=dice2[i];
        }
    }
    else if(dir==4){
        dice2[1]=dice[5];
        dice2[2]=dice[1];
        dice2[3]=dice[3];
        dice2[4]=dice[4];
        dice2[5]=dice[6];
        dice2[6]=dice[2];
        for(int i=1;i<=6;i++){
            dice[i]=dice2[i];
        }
    }    //이동 및 주사위 돌리기 끝

    int num= arr[x][y];
    int visited[30][30]={0,};
    int count=0;
    queue<pair<int,int>>Q;
    Q.push(make_pair(x,y));
    visited[x][y]=1;
    while(!Q.empty()){
        int a = Q.front().first;
        int b= Q.front().second;
        Q.pop();
        count++;
        for(int i=1;i<=4;i++){
            int ax= a+dx[i];
            int by= b+dy[i];
            if(ax<1 || by<1 || ax>n || by>m)
                continue;
            if(visited[ax][by]==1 || arr[ax][by]!=num)
                continue;
            Q.push(make_pair(ax,by));
            visited[ax][by]=1;
        }
    }
    ans += count * num;
    //방향전환
    if(arr[x][y] < dice[6]){
        if(dir==1)
            dir=3;
        else if(dir==3)
            dir=2;
        else if(dir==2)
            dir=4;
        else
            dir=1;
    }
    else if(arr[x][y]>dice[6]){
        if(dir==1)
            dir=4;
        else if(dir==3)
            dir=1;
        else if(dir==2)
            dir=3;
        else
            dir=2;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<k;i++){
        move();
    }
    cout<<ans;
}