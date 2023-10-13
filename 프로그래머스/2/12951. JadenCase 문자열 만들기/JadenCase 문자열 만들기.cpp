#include<bits/stdc++.h>
using namespace std;

string solution(string s) {
    string ans="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            ans+=s[i];
            continue;
        }
        if(i==0){
            if(isupper(s[i]) || islower(s[i]) )
                ans+=toupper(s[i]);
            else
                ans+=s[i];
        }
        else{
            if(s[i-1]==' '){
                if(isupper(s[i]) || islower(s[i]) )
                    ans+=toupper(s[i]);
                else
                    ans+=s[i];   
                }
            else
                ans+=tolower(s[i]);
        }
    }
    return ans;
}