#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
map<string,int> m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int len = clothes.size();
    for(auto v : clothes){
        string value = v[0];
        string key = v[1];
        if(m.find(key)==m.end())
            m[key]=1;
        else{
            m[key]++;
        }
    }
    if(m.size()==1){
        for(auto e : m){
            return e.second;
        }
    }
    
    for(auto e : m){
        answer *=(e.second+1);
    }
    return answer-1;
}