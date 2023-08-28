#include<iostream>
#include<vector>

using namespace std;
int n,m,h;  //n : 세로줄 , h : 가로줄
int arr[100][400]={0,}; //사다리 정보 저장
int arr2[100][400]={0,};
int ans=0;
vector<pair<int,int>> candidate;
int check(){  //지금 arr상태에서 i to i 가 되는지 체크
    for(int j=1;j<=n;j++){ //세로줄
        int num=j; //현재 가로줄
        for(int i=1;i<=h;i++){ //가로줄
            if(arr[i][num]==1){
                num++;
            }
            else if(arr[i][num-1]==1){
                num--;
            }
        }
        if(num!=j)
            return -1; //i -> i 가 안됨
    }
    return 1;
}
void arr_init(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=arr2[i][j];
        }
    }
}
void make_candidate(){  //현재 상태의 arr에서 비어있는 가로선 추출
    for(int i=1;i<=h;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]==0)
                candidate.push_back(make_pair(i,j));
        }
    }
}
void backtrack(int depth,int num, int start){   //depth는 현재 뽑은 개수 , num은 뽑아야하는 개수, start는 스타트
    if(num==depth){
        if(check()==1){
            ans=1;
            return;}
        else
            return;
    }
    for(int i=start;i<candidate.size();i++){
        int x = candidate[i].first;
        int y = candidate[i].second;
        if(arr2[x][y+1]==1 || arr2[x][y-1]==1)
            continue;
        arr[x][y]=1;
        backtrack(depth+1,num,i+1);
        arr[x][y]=0;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr2[a][b]=1;
    }
    make_candidate();
    for(int i=0;i<=3;i++){
        backtrack(0,i,0);
        if(ans==1){
            cout<<i;
            return 0;
        }
        arr_init();
    }
    cout<<-1;

}