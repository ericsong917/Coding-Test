#include <string>
#include <vector>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<iostream>
using namespace std;
int answer = 99999;
int solution(int n, vector<vector<int>> wires) {
    for(int i=0;i<wires.size();i++){
        //i는 제외
        vector<vector<int>> tmp = wires;
        tmp.erase(tmp.begin()+i);
        map<int,set<int>> M;
        for(int j=0;j<tmp.size();j++){ //Map 그리기
            int f = tmp[j][0];
            int s = tmp[j][1];
            M[f].insert(s);
            M[s].insert(f);
        }
        queue<int> Q;
        Q.push(1);
        int visited[101]={0,};
        visited[1]=1;
        int cnt=0;
        while(!Q.empty()){
            int top = Q.front();
            Q.pop();
            cnt++;
            for(auto k : M[top]){
                if(visited[k]!=1){
                    Q.push(k);
                    visited[k]=1;
                }
            }
        }
        cout<<cnt<<' ';
        if( abs(n-2*cnt) < answer )
            answer = abs(n-2*cnt);
    }
    return answer;
}