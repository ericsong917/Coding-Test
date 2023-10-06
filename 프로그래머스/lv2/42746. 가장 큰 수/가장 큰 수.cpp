#include <string>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;
bool cmp(string a, string b){
    
    a +=a;
    a+=a;
    b+=b;
    b+=b;
    return a>b;
}

string solution(vector<int> numbers) {
    vector<string> number;
    for(auto e : numbers){
        number.push_back(to_string(e));
    }
    sort(number.begin(),number.end(),cmp);
    string ans="";
    for(auto s : number){
        ans+=s;
    }
    if(ans[0]=='0')
        return "0";
    return ans;
}