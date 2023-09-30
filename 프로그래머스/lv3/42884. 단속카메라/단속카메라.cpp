#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end());
    vector<vector<int>> ans;
    for(int i=0; i<routes.size();i++){
        if(ans.size()==0)
            ans.push_back(routes[i]);
        int flag=0;
        for(int j=0;j<ans.size();j++){
            vector<int> prev, now;
            prev=ans[j];
            now = routes[i];
            //포함되는 경우
            if(prev[0]<=now[0] && prev[1]>=now[1]){
                ans[j] = now ;
                flag=1;
                break;
            }
            //교집합 존재
            else if(prev[1]>=now[0]){
                ans[j][0] = now[0];
                ans[j][1] = prev[1];
                flag=1;
                break;
            }
            
            else{ //교집합 존재 x
                continue;
            }
        }
        if(flag==0)
            ans.push_back(routes[i]);
    }
    
    return ans.size();
}