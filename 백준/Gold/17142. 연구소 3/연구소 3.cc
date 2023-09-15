#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int length;
int n,m;
int arr[100][100]; //초기 배열
vector<pair<int,int>> virus; // 바이러스 칸 정보 저장
vector<pair<int,int>> virus_pick(100); // 3M개 뽑은 바이러스, 비활성 바이러스가 활성으로 바꼈을때도 여기다가 추가
vector<pair<int,int>> blank;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int minn=9999;
void print_arr(int a[100][100]){
    cout<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
}
int check_ans(int a[100][100]){
    int maxx=0;
    for(auto e: blank){
        if(a[e.first][e.second]==10000)
            return 10000;
        else
            if(maxx<a[e.first][e.second])
                maxx=a[e.first][e.second];
    }

    return maxx;
}
void bfs(int depth, int start){
    if(depth==m){
        int arr2[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){//벽
                    arr2[i][j]=-3;}
                else{
                    arr2[i][j]=10000;}
            }
        } //arr2 생성     벽 -3   나머지 1000   //arr에는 정보만 저장(빈칸인지 바이러스인지) , arr2에는 시간정보 저장
        queue<pair<int,int>> Q;
        for(int i=0; i<m;i++ ){
            auto e = virus_pick[i];
            Q.push(e);
            arr2[e.first][e.second]=0;
            }    
// 초기 활성 바이러스 칸을 0으로 바꾸기
        while(!Q.empty()){  
            int ax= Q.front().first;
            int ay = Q.front().second;
            Q.pop();
            for(int i=0;i<4;i++){
                int x=ax+dx[i];
                int y=ay+dy[i];
                if(x<0 || y<0 || x>=n || y>=n || arr[x][y]==-3)  //범위 벗어나거나 벽 처리
                    continue;
                if(arr2[ax][ay]+1 >= arr2[x][y])  // 이동할 칸이 0이 아닌 것 중에 이미 더 적은 시간으로 방문했으면 무시
                    continue;
                arr2[x][y]=arr2[ax][ay]+1;
                Q.push(make_pair(x,y));
            }
        }
        int tmp=check_ans(arr2);
        if(tmp<10000){
            if(minn>tmp)
                minn=tmp;
                }
        // print_arr(arr2);
        return;
        
    }
    for(int i=start;i<length;i++){
        virus_pick[depth]=virus[i];
        bfs(depth+1,i+1);
    }
    
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];  //0 빈칸 , 1 벽 , 2 바이러스
            if(arr[i][j]==2){
                virus.push_back(make_pair(i,j));
            }
            else if(arr[i][j]==0)
                blank.push_back(make_pair(i,j));
        }
    }
    length=virus.size();
    bfs(0,0);
    if(minn==9999)
        cout<<-1;
    else   
        cout<<minn;

}