#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> m;
    char before, now;
    m[words[0]]++;
    before = words[0][words[0].size()-1];
    for(int i = 1; i < words.size();i++){
        now = words[i][0];
        m[words[i]]++;
        if(before != now || m[words[i]] == 2){
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }

        before = words[i][words[i].size()-1];
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}