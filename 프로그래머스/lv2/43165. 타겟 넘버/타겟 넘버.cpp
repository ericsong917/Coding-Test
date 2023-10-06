#include <string>
#include <vector>
using namespace std;

int len ;
int t;
int ans=0;
vector<int> nums;
void backtrack(int depth, vector<int> vec){
    if(depth == len){
        int sum=0;
        for(auto e : vec){
            sum+=e;
        }
        if(sum==t)
            ans++;
        return;
    }
    vector<int> tmp = vec;
    tmp.push_back(nums[depth]);
    backtrack(depth+1,tmp);
    tmp = vec;
    tmp.push_back(nums[depth] * -1);
    backtrack(depth+1, tmp);
}
int solution(vector<int> numbers, int target) {
    nums = numbers;
    len = numbers.size();
    t=target;
    vector<int> a;
    backtrack(0,a);
    return ans;
}