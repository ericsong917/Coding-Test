#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> wheel[5];
int n;
int num, dir;
//12시 방향 0, 회전상관있는파트 2
//n극은 0, s극은 1
//1 시계방향 -1 반시계방향
vector<int> turn(vector<int> v){
    vector<int> v1;
    v1=v;
    int temp=v1.back();
    v1.pop_back();
    vector<int> v2;
    v2.push_back(temp);
    for(int i=0;i<=6;i++){
        v2.push_back(v1[i]);
    }
    return v2;
}
vector<int> turn_reverse(vector<int> v){
    int temp=v.front();
    vector<int>v2;
    for(int i=1;i<=7;i++){
        v2.push_back(v[i]);
    }
    v2.push_back(temp);
    return v2;
}
int score(){
    int sum=0;
    if(wheel[1][0]==1){
        sum+=1;
    }
    if(wheel[2][0]==1){
        sum+=2;
    }
    if(wheel[3][0]==1){
        sum+=4;
    }
    if(wheel[4][0]==1){
        sum+=8;
    }
    return sum;

}
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string temp;
	for(int i=1;i<=4;i++){
        cin>>temp;
    	for(int j=0;j<8;j++){
            int temp2=temp[j]-'0';
        	wheel[i].push_back(temp2);
        }
	}
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num>>dir;
        if(dir==1){
            
            int left=num-1;
            int right=num+1;
            int lleft=num-2;
            int rright=num+2; 
            int llleft=num-3;
            int rrright=num+3;
            if(left>=1){
                if(wheel[left][2]!=wheel[num][6]){
                    if(lleft>=1){
                        if(wheel[lleft][2]!=wheel[left][6]){
                            if(llleft>=1){
                                if(wheel[llleft][2]!=wheel[lleft][6]){
                                    wheel[llleft]=turn_reverse(wheel[llleft]);
                                }
                            }
                            wheel[lleft]=turn(wheel[lleft]);
                            }}
                    wheel[left]=turn_reverse(wheel[left]);}
            }
            if(right<=4){
                if(wheel[right][6]!=wheel[num][2]){
                    if(rright<=4){
                        if(wheel[rright][6]!=wheel[right][2]){
                            if(rrright<=4){
                                if(wheel[rrright][6]!=wheel[rright][2]){
                                    wheel[rrright]=turn_reverse(wheel[rrright]);
                                }
                            }
                            wheel[rright] = turn(wheel[rright]);}
                            }
                    wheel[right]=turn_reverse(wheel[right]);}
                    }
            wheel[num]=turn(wheel[num]);
        }
        else{
            
            int left=num-1;
            int right=num+1;
            int lleft=num-2;
            int rright=num+2; 
            int llleft=num-3;
            int rrright=num+3;
            if(left>=1){
                if(wheel[left][2]!=wheel[num][6]){
                    if(lleft>=1){
                        if(wheel[lleft][2]!=wheel[left][6]){
                            if(llleft>=1){
                                if(wheel[llleft][2]!=wheel[lleft][6]){
                                    wheel[llleft]=turn(wheel[llleft]);
                                }
                            }
                            wheel[lleft]=turn_reverse(wheel[lleft]);
                            }}
                    wheel[left]=turn(wheel[left]);}
            }
            if(right<=4){
                if(wheel[right][6]!=wheel[num][2]){
                    if(rright<=4){
                        if(wheel[rright][6]!=wheel[right][2]){
                            if(rrright<=4){
                                if(wheel[rrright][6]!=wheel[rright][2]){
                                    wheel[rrright]=turn(wheel[rrright]);
                                }
                            }
                            wheel[rright] = turn_reverse(wheel[rright]);}
                            }
                    wheel[right]=turn(wheel[right]);}
                    }
            wheel[num]=turn_reverse(wheel[num]);
        }
    }
    cout<<score();
}

