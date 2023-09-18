#include<iostream>
#include<vector>
#include<string>
//to_string   stoi
using namespace std;
//1~26
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string word;
    cin>>word;
    int dp[5001]={0,};
    if(word[0]!='0')
        dp[0]=1;
    if(word[0]=='0'){
        cout<<0;
        return 0;
    }
    if(word[1]!='0')
        dp[1]=1;
    int num = stoi(word.substr(0,2));
    if(num>=1 && num<=26 && (word.substr(0,2))[0] != '0')
        dp[1]++;

    for(int i=2;i<word.length();i++){
        //n-1
        if(word[i]!='0')
            dp[i]+=dp[i-1];
        //n-2
        int tmp = stoi(word.substr(i-1,2));
        if(tmp >=1 && tmp<=26 && (word.substr(i-1,2))[0] != '0')
            dp[i]+=dp[i-2];
        dp[i]%=1000000;
    }
    cout<<dp[word.length()-1];
}