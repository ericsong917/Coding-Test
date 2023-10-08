#include<iostream>
#include<vector>
using namespace std;
int n; //도시의 개수
vector<long long> length; //도로의 길이
vector<long long> oil_price; //기름 가격
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long ans=0;
    long long min_price = 1000000001;
    long long tmp;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>tmp;
        length.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        oil_price.push_back(tmp);
    }

    for(int i=0;i<n-1;i++){
        if(min_price > oil_price[i]){
            min_price = oil_price[i];
            ans += (min_price * length[i]);
        }
        else{
            ans+=(min_price * length[i]);
        }
        
    }
    cout<<ans;
    return 0;
}