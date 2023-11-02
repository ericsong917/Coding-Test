#include<bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> Q;
    for(auto c : s){
        if(Q.empty())
            Q.push(c);
        else{
            if(Q.top()==c)
                Q.pop();
            else
                Q.push(c);
        }
    }
    if(Q.empty())
        answer=1;
    else
        answer=0;
    return answer;
}