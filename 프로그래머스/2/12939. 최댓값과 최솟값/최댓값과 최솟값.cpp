#include <string>
#include <vector>
#include<sstream>
#include<algorithm>
using namespace std;

vector<int> split(string a){
    istringstream ss(a);
    string buf;
    vector<int> vec;
    while(getline(ss,buf,' ')){
        vec.push_back(stoi(buf));
    }
    return vec;
}
string solution(string s) {
    vector<int> ans = split(s);
    sort(ans.begin(),ans.end());
    int low = ans[0];
    int high = ans[ans.size()-1];
    
    string answer = "";
    answer+= to_string(low);
    answer+=" ";
    answer+=to_string(high);
    return answer;
}