#include<iostream>
#include<vector>
using namespace std;
int r ,c;
int arr[100][100];
int t;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
vector<pair<int,int>> dust;
pair<int,int> refresh[2];
void count(){
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==-1){
                continue;
            }
            sum+=arr[i][j];
        }
    }
    cout<<sum;
}
void print_arr(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
    cout<<"\n";
}
void dust_init(){ //미세먼지 있는 칸 담기
    dust.clear();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]>0){
                dust.push_back(make_pair(i,j));
            }
        }
    }
}
void spread(){
    int arr2[100][100]={0,};
    for(auto e : dust){
        int count=0;
        int x=e.first;
        int y=e.second;
        for(int i=0;i<4;i++){
            int ax=x+dx[i];
            int ay=y+dy[i];
            if(ax<0 || ay<0 || ax>=r || ay>=c)
                continue;
            if(arr[ax][ay]==-1)
                continue;
            count++;
            arr2[ax][ay] += (arr[x][y]/5);
        }
        arr2[x][y]-= ((arr[x][y]/5)*count);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j]=arr[i][j]+arr2[i][j];
        }
    }

}
void clean(){
    //위쪽
    int arr3[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr3[i][j]=arr[i][j];
        }
    }
    int x= refresh[0].first;
    int y= refresh[0].second;
    for(y=y+1;y<c-1;y++){
        arr3[x][y+1]=arr[x][y];
    } 
    for(x;x>0;x--){
        arr3[x-1][y]=arr[x][y];
    }
    for(y;y>0;y--){
        arr3[x][y-1]=arr[x][y];
    }
    for(x;x<refresh[0].first-1;x++){
        arr3[x+1][y]=arr[x][y];
    }
    //공청 옆 처리
    arr3[refresh[0].first][refresh[0].second+1]=0;
    
    //아래쪽
    x= refresh[1].first;
    y= refresh[1].second;
    for(y=y+1;y<c-1;y++){
        arr3[x][y+1]=arr[x][y];
    } 
    for(x;x<r-1;x++){
        arr3[x+1][y]=arr[x][y];
    }
    for(y;y>0;y--){
        arr3[x][y-1]=arr[x][y];
    }
    for(x;x>refresh[1].first+1;x--){
        arr3[x-1][y]=arr[x][y];
    }
    arr3[refresh[1].first][refresh[1].second+1]=0;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j]=arr3[i][j];
        }
    }

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>r>>c>>t;
    int temp=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1){
                refresh[temp++]=make_pair(i,j);
            }
        }
    }
    for(int i=0;i<t;i++){
        dust_init();
        spread();
        clean();
    }
    count();

}