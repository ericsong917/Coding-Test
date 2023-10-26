#include<bits/stdc++.h>
using namespace std;
int zeros=0;
string change(string str){
    int cnt=0;
    for(auto c : str){
        if(c=='1')
            cnt++;
        else{
            zeros++;
        }
    }
    string tmp="";
    while(cnt>0){
        tmp = to_string(cnt%2) + tmp;
        cnt/=2;
    }
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count=0;
    while(1){
        if(s=="1")
            break;
        s=change(s);
        count++;
    }
    answer.push_back(count);
    answer.push_back(zeros);
    return answer;
}