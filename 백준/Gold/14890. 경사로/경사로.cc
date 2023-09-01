#include<iostream>
#include<vector>
using namespace std;
int n, l; //l 경사로의 길이
int ans=0;
int arr[200][200];
int visit[200][200]={0,}; //경사로 정보저장
int check_way(int tmp2[200],int row){ //가로방향 가능한지 체크
    int visit2[200]={0,};
    for(int i=1;i<n;i++){
        if(tmp2[i]==tmp2[i-1]){
            //같은층이면 경사로 안놓아도 됨.
            continue;}
        else{ //경사로 놓아야함, 높이차이는 1이어야함
            if(tmp2[i]-tmp2[i-1]==1){ //왼쪽 방향으로 놓기   
                if(i-l<0){ //범위 넘어감
                    return -1;}
                int same=tmp2[i-1];
                for(int j=1;j<=l;j++){
                    if(visit[row][tmp2[i-j]]==1 || visit2[i-j]==1){
                        return -1;
                        }
                    if(same!=tmp2[i-j]){
                        return -1;}
                }
                for(int j=1;j<=l;j++){
                    visit2[i-j]=1;
                }
            }
            else if(tmp2[i-1]-tmp2[i]==1){  //오른쪽 방향으로 놓기 
                if((i+l-1)>=n)
                    return -1;
                int same=tmp2[i];
                for(int j=0;j<l;j++){
                    if(visit[row][tmp2[i+j]]==1 || visit2[i+j]==1){
                        return -1;}
                    if(same!=tmp2[i+j]){
                        return -1;}
                }
                for(int j=0;j<l;j++){
                    visit2[i+j]=1;
                }
                i=i+l-1;
                
            }
            else{
                return -1;
            }
        }
    }
    //성공적으로 여기까지 나오면 길이 됐다는 뜻
    for(int i=0;i<n;i++){  //visit 정보 복사
        if(visit2[i]==1)
            visit[row][i]=1;
    }
    return 1;
}
int check_way2(int tmp2[200],int column){ //가로방향 가능한지 체크
    int visit2[200]={0,};
    for(int i=1;i<n;i++){
        if(tmp2[i]==tmp2[i-1]){
            //같은층이면 경사로 안놓아도 됨.
            continue;}
        else{ //경사로 놓아야함, 높이차이는 1이어야함
            if(tmp2[i]-tmp2[i-1]==1){ //왼쪽 방향으로 놓기   
                if(i-l<0){ //범위 넘어감
                    return -1;}
                int same=tmp2[i-1];
                for(int j=1;j<=l;j++){
                    if(visit2[i-j]==1){
                        return -1;
                        }
                    if(same!=tmp2[i-j]){
                        return -1;}
                }
                for(int j=1;j<=l;j++){
                    visit2[i-j]=1;
                }
            }
            else if(tmp2[i-1]-tmp2[i]==1){  //오른쪽 방향으로 놓기 
                if((i+l-1)>=n)
                    return -1;
                int same=tmp2[i];
                for(int j=0;j<l;j++){
                    if( visit2[i+j]==1){
                        return -1;}
                    if(same!=tmp2[i+j]){
                        return -1;}
                }
                for(int j=0;j<l;j++){
                    visit2[i+j]=1;
                }
                i=i+l-1;
                
            }
            else{
                return -1;
            }
        }
    }
    //성공적으로 여기까지 나오면 길이 됐다는 뜻
    for(int i=0;i<n;i++){  //visit 정보 복사
        if(visit2[i]==1)
            visit[column][i]=1;
    }
    return 1;


}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){      //가로방향 길 체크
        int tmp[200];  //해당 길을 담을 임시 배열
        for(int j=0;j<n;j++){
            tmp[j]=arr[i][j];
        }
        //길이 되는지 체크.
        // cout<<i<<'\n';
        if(check_way(tmp,i)==1){ //row기준
            ans++;}
    }
    for(int i=0;i<n;i++){
        int tmp[200];
        for(int j=0;j<n;j++){
            tmp[j]=arr[j][i];
        }
        if(check_way2(tmp,i)==1){ //row기준
            ans++;}
    }
    cout<<ans;
}