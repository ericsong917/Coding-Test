#include<bits/stdc++.h>
using namespace std;

int solution(int n){
    int answer = 0;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sum = (i+j)*(j-i+1)/2;
            if(sum==n){
                // cout<<i<<' '<<j<<'\n';
                answer++;
                break;}
            if(sum>n)
                break;
        }
    }
    return answer;
}