#include <string>
#include <vector>
#include<queue>
#include<algorithm>
//priority Queue에 넣기, 실행하기, 
using namespace std;
struct cmp
{
    bool operator()(vector<int> a,vector<int> b)
    {
        return a[1]>b[1];
    }
};
int solution(vector<vector<int>> jobs) {
    int ans = 0;
    int idx = 0;
    int t = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>, vector <vector<int> >, cmp > q;
    while(idx < jobs.size() || !q.empty() ){
        if(idx<jobs.size() && t >= jobs[idx][0] ){
            q.push(jobs[idx]);
            idx++;
            continue;
        }
        if(!q.empty()){
            t += q.top()[1];
            ans = ans + (t-q.top()[0]);
            q.pop();
        }
        else{
            t = jobs[idx][0];
        }
    }
    
    return ans / jobs.size();
}