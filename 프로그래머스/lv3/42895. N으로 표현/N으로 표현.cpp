#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
//8번이 최대
vector<int> arr[9];
int solution(int N, int number) {
    int answer = -1;
    int flag=0;
    for(int i=1;i<=8;i++){
        if(flag==1)
            break;
        if(i==1){
            if(number==N){
                return 1;
            }
            arr[1].push_back(N);
            continue;
        }
        else{
            for(int j=1;j<=i;j++){
                int first = j;
                int second = i-j;
                for(int k=0;k<arr[first].size();k++){
                    for(int p=0;p<arr[second].size();p++){
                        int a,b,c,d,b2,d2;
                        a= arr[first][k] + arr[second][p];
                        b= arr[first][k] - arr[second][p];
                        c= arr[first][k] * arr[second][p];
                        if(arr[second][p]!=0){
                            d= arr[first][k] / arr[second][p];
                            arr[i].push_back(d);
                        }
                        arr[i].push_back(a);
                        arr[i].push_back(b);
                        arr[i].push_back(c);
                        int tmp=0;
                        for(int cnt=0;cnt<i;cnt++){
                            tmp+= pow(10,cnt);
                        }
                        tmp *= N;
                        arr[i].push_back(tmp);
                        if(a==number || b==number || c==number || d==number || tmp==number) {
                            answer = i;
                            flag=1;
                        }
                    }
                }
            }
        }
    }
    if(answer >8)
        answer=-1;
    return answer;
}