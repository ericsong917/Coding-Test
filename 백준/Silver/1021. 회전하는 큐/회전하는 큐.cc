#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  int ans=0;
  deque<int> d;

  cin>>N>>M;
  for(int i=1;i<=N;i++){
    d.push_back(i);
  } 
  for(int i=0;i<M;i++){
    int n;
    cin>>n;
    int k;

    for(int i=0;i<N;i++){
      if(d[i]==n) {
      k=i+1;
      break;
      }
    }
    int len= (N%2==1) ? (N+1) : (N); 
    if(k<=len/2){
      while(d.front()!=n){
        int num=d.front();
        d.pop_front();
        d.push_back(num);
        ans++;
      }
      if(d.front()==n) {
        d.pop_front();
        N--;}
    }
    else{
      while(d.front()!=n){
        int num=d.back();
        d.push_front(num);
        d.pop_back();
        ans++;
      }
      if(d.front()==n){
        d.pop_front();
        N--;}
    }
    
  }
  cout<<ans;
}