#include <string>
#include <vector>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;

bool is_prime(int num){
    if(num==1 || num==0)
        return false;
    for(int i=2;i<num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
string nums;
set<int> ans;
int check[10]={0,};
void backtrack(int depth,string now_string,int check_size){
    if(depth==check_size){
        int num = stoi(now_string);
        if(is_prime(num)){
            ans.insert(num);
        }
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(check[i]==1)
            continue;
        else{
            check[i]=1;
            backtrack(depth+1,now_string+nums[i],check_size);
            check[i]=0;
        }
    }
}
int solution(string numbers) {
    nums=numbers;
    for(int i=1;i<=numbers.size();i++){
        backtrack(0,"",i);
    }
    return ans.size();
}