#include <string>
#include <vector>
#include <queue>
using namespace std;
long long ans=0;

struct cmp{
    bool operator()(int x , int y){
        return x<y;
    }
};

long long solution(int n, vector<int> works) {
    priority_queue<int, vector<int>, cmp> pq;
    for(auto e: works){
        pq.push(e);
    }
    while(n--){
        int top = pq.top();
        if(top<=0)
            break;
        else{
            pq.pop();
            pq.push(top-1);
        }
    }
    long long ans=0;
    while(!pq.empty()){
        int tmp = pq.top();
        ans+= (long long)(tmp*tmp);
        pq.pop();
    }
    return ans;
}