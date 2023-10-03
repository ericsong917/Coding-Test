#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int len;
int ans=0;
vector<vector<string>> vec;
int visited[10]={0,};
vector<string>usr_id,bn_id;
bool compare(string a, string b){ //a가 '*' 포함
    if(a.size() != b.size())
        return false;
    
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i] && a[i]!='*')
            return false;
    }
    return true;
}

void backtrack(int depth,vector<string> tmp){
    sort(tmp.begin(),tmp.end());
    if(depth == bn_id.size()){
        if(vec.size()==0){
            ans++;
            vec.push_back(tmp);
            for(auto e : tmp){
                cout<<e<<' ';
            }
            cout<<'\n';
            return;
        }
        else{
            for(auto v2 : vec){ //현재 목록들
                if(v2.size() != tmp.size())
                    continue;
                sort(v2.begin(),v2.end());
                int flag=0;
                for(int l=0;l<v2.size();l++){
                    if(v2[l]!=tmp[l])
                        flag=1;
                }
                //v2와 tmp가 일치하면 tmp는 추가될수 없다.
                if(flag==0)
                    return;
            }
        }
        for(auto e : tmp){
            cout<<e<<' ';
        }
        cout<<'\n';
        ans++;
        vec.push_back(tmp);
        return;
    }
    for(int i=0;i<usr_id.size();i++){
        if(compare(bn_id[depth],usr_id[i])){
            if(visited[i]==1)
                continue;
            visited[i]=1;
            vector<string> tmp2 = tmp;
            tmp2.push_back(usr_id[i]);
            backtrack(depth+1,tmp2);
            visited[i]=0;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<string> tmp2;
    usr_id = user_id;
    bn_id = banned_id;
    backtrack(0,tmp2);
    return ans;
}