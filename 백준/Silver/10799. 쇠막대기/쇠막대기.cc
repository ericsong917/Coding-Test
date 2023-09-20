#include<bits/stdc++.h>
using namespace std;
int ans=0;
char behind;
int main(){
    int count;
    ios::sync_with_stdio(0);
    vector <char> vec;
    char ch=' ';
    stack<char> stk;
    string str;
    cin>>str;
    for(auto e: str){
        vec.push_back(e);
    }
    for(auto e: vec){
        if(e=='('){stk.push(e);}
        else{//e==')'
            if(behind=='('){ //laser
                stk.pop();
                ans+=stk.size();
            }
            else{
                stk.pop();
                ans+=1;
            }
        }
        behind=e;
    }
    cout<<ans;
    }
