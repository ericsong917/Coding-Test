#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    class cmp { //내림차순
        public :
        bool operator()(int a, int b){
            return a<b;
        }
    };
    class cmp2 { //오름차순
        public :
        bool operator()(int a, int b){
            return a > b;
        }
    };
    
    priority_queue<int,vector<int>,cmp> max_q;
    priority_queue<int,vector<int>,cmp2> min_q;
    int num=0; //숫자 개수
    for(auto e : operations){
        if(e[0]=='I'){ //삽입
            string tmp = e.substr(2);
            int n = stoi(tmp);
            num++;
            max_q.push(n);
            min_q.push(n);
        }
        else{
            string tmp = e.substr(2);
            if(num==0)
                continue;
            int n = stoi(tmp);
            if(n==-1){ //최소값 pop
                min_q.pop();
            }
            else{ //최대값 pop
                max_q.pop();
            }
            num--;
            if(num==0){
                while(!min_q.empty()){
                    min_q.pop();
                }
                while(!max_q.empty()){
                    max_q.pop();
                }
            }
        }
    }
    if(num==0){
        answer[0]=0;
        answer[1]=0;
    }
    else{
        answer[0] = max_q.top();
        answer[1] = min_q.top();
    }
    return answer;
}