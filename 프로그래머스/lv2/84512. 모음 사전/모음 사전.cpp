#include <string>
#include <vector>
#include<iostream>
using namespace std;
string str = "AEIOU";
string w ;
int answer;
int flag=0;
int cnt=0;
void backtrack(string now){
    // cout<<now<<' '<<cnt<<'\n';
    if( now == w ){
        answer=cnt;
    }
    if(now.size()==5){
        return;
    }

    for(int i=0;i<5;i++){
        cnt++;
        backtrack(now+str[i]);
    }
}
int solution(string word) {
    w=word;
    backtrack("");
    return answer;
}