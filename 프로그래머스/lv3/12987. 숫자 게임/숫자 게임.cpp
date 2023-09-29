#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int ans=0;
    deque<int>a,b;
    for(int i=0;i<A.size();i++){
        a.push_back(A[i]);
        b.push_back(B[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(!b.empty()){
        if(a[0]<b[0]){
            a.pop_front();
            b.pop_front();
            ans++;
        }
        else{
            a.pop_back();
            b.pop_front();
        }
    }
    return ans;
}