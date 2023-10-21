#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum= brown + yellow;
    for(int width = sum ; width>=1; width--){
        int height;
        if(sum%width!=0)
            continue;
        height = sum/width;
        if( (height-2)*(width-2)==yellow ){
            answer.push_back(width);
            answer.push_back(height);
            return answer;
        }
            
    }
    return answer;
}