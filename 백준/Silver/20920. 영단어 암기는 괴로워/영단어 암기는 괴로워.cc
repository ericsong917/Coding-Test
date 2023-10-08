#include<bits/stdc++.h>
using namespace std;
vector<string> arr;
map<string,int> cnt;
string tmp;
//자주나오는 단어일수록
//단어 길수록
//알파벳 순으로 앞에 있는 단어일수록
//길이가 M이상의 단어만 외운다
bool cmp(string a, string b){
    if(cnt[a]==cnt[b]){
        if(a.size()==b.size()){
            return a<b;
        }
        else{
            return a.size()>b.size();
        }
    }
    else{
        return cnt[a]>cnt[b]; 
    }
}
int n,m;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp.size()<m)
            continue;
        if(cnt.find(tmp)==cnt.end()){
            cnt.insert({tmp,0});
            arr.push_back(tmp);
            }
        else
            cnt[tmp]++;
    }
    sort(arr.begin(),arr.end(),cmp);
    for(auto e : arr){
        cout<<e<<'\n';
    }

}
    