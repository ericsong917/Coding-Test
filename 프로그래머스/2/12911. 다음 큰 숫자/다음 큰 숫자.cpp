#include<bits/stdc++.h>
using namespace std;
int countone(int num){
    int cnt=0;
    while(num>0){
        if(num%2==1)
            cnt++;
        num/=2;
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
    int n_cnt = countone(n);
    int num = n+1;
    cout<<n_cnt;
    while(1){
        if(countone(num)==n_cnt){
            answer = num;
            break;
        }
        num++;
    }
    return answer;
}