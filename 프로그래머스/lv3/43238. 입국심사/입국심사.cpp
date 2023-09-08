#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long min_t = 1 ;
    long long max_t = (long long)(*max_element(times.begin(), times.end())) * n;
    long long start = min_t;
    long long end = max_t;
    long long mid;
    long long answer=0;
    while(start <= end){
        mid = (start + end)/2;
        long long cnt=0;
        for(int i=0;i<times.size();i++){
            cnt += mid / times[i];
        }
        
        if(cnt <n){
            start = mid +1;
        }
        else{
            answer = mid;
            end = mid-1;
        }

    }
    return answer;
}