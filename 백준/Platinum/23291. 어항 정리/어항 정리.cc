#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<math.h>
#include<string.h>
using namespace std;
int dow[101][101]={0};
int n, k; //밀가루 배열으 ㅣ크기, 최댓값과 최솟값의 차이
void print_dow(int arr[101][101]) {
	for (int i = 100-n; i <=100; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void step1() {
	int m = 100000;
	for (int i = 0; i < n; i++) {
		if (dow[100][i] < m)
			m = dow[100][i];
	}
	for (int i = 0; i < n; i++) {
		if (dow[100][i] == m)
			dow[100][i]++;
	}
}
int first[101][101] = { 0, };
int second[101][101] = { 0, };
void step2() {
	int end_flag = 0;
	//구분, 왼쪽꺼 시계방향회전, 내리기(second에 합치기)
	while (1) {

		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));
		if (dow[99][0] == 0) { //처음
			int num = dow[100][0];
			for (int i = 0; i < n - 1; i++) {
				dow[100][i] = dow[100][i + 1];
			}
			dow[100][n - 1] = 0;
			dow[99][0] = num;
			//print_dow(dow);
		}
		else { //나중
			int split_idx = 0;
			for (int j = 0; j < n; j++) {
				if (dow[99][j] > 0 && dow[99][j + 1] == 0) {
					split_idx = j;
					break;
				}
			}
			//first 복사
			for (int j = 0; j <= split_idx; j++) {
				int i = 100;
				while (dow[i][j] != 0) {
					first[i][j] = dow[i][j];
					i--;
				}
			}
			//first를 시계방향으로 회전 => first_tmp
			int first_tmp[101][101] = { 0 };
			for (int i = 0; i < 101; i++) {
				for (int j = 0; j < 101; j++) {
					first_tmp[i][j] = first[101- j - 1][i];
				}
			}
			//cout << first_tmp[0][0] << first_tmp[0][1];

			//second 복사 split_idx +1만큼 왼쪽으로 보내야함
			int i = 0;
			for (int j = split_idx + 1; dow[100][j] != 0 && j < n; j++) {
				second[100][i] = dow[100][j];
				i++;
			}

			//second에 first_tmp을 내림
			int cnt = 0; //몇칸내려야하는지
			for (int i = 99; i >= 0; i--) {
				if (first_tmp[i][0] == 0)
					cnt++;
				else
					break;
			}
			for (int i = 0; i <= 99 - cnt; i++) {
				for (int j = 0; j < n; j++) {
					second[i + cnt][j] = first_tmp[i][j];
				}
			}
			//멈출지 체크
			int floor = 0;
			int top = 0;
			for (int j = 0; j < n; j++) {
				if (second[100][j] > 0)
					floor++;
				else
					break;
			}
			for (int j = 0; j < n; j++) {
				if (second[99][j] > 0)
					top++;
				else
					break;
			}
			if (top > floor) {
				end_flag = 1;
			}
			if (end_flag == 1)
				break;
			else
				copy(&second[0][0], &second[100][101], &dow[0][0]);
			//print_dow(dow);
		}
	}
}
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void step3() {
	int tmp[101][101] = { 0 };
	int visited[101][101] = { 0 };
	for (int i = 0; i<101; i++) { //값처리
		for (int j = 0; j < 101; j++) {
			if(dow[i][j]==0)	
				continue;
			visited[i][j] = 1;
			for (int dir = 0; dir < 4; dir++) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if (x < 0 || y < 0 || x >= 101 || y >= 101)
					continue;
				if (dow[x][y] == 0)
					continue;
				if (visited[x][y] == 1)
					continue;
				int now_val = dow[i][j];
				int next_val = dow[x][y];
				int d = abs(now_val - next_val) / 5;
				if (now_val > next_val) {
					tmp[i][j] -= d;
					tmp[x][y] += d;
				}
				else {
					tmp[i][j] += d;
					tmp[x][y] -= d;
				}
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dow[i][j] += tmp[i][j];
		}
	}
	vector<int> tmp_vec;
	for (int j =0 ; j< 101; j++) {
		for (int i = 100; i >=0; i--) {
			if (dow[i][j] > 0)
				tmp_vec.push_back(dow[i][j]);
		}
	}
	fill(&dow[0][0], &dow[100][101], 0);
	for (int i = 0; i < tmp_vec.size(); i++) {
		dow[100][i] = tmp_vec[i];
	}
}

void step4() { //두번 반으로 접기
	int next_dow[101][101] = { 0 };
		for (int j = 0; j < n / 2; j++) {
			next_dow[100][j] = dow[100][j + (n / 2)];
			next_dow[99][j] = dow[100][(n / 2) - 1 - j];
		}
		//print_dow(next_dow);
		int second_half = n / 2 / 2; //2
		int last_dow[101][101] = { 0 };
		for(int i=100;i>=99;i--){
			for (int j = 0; j < second_half; j++) {
				last_dow[i][j] = next_dow[i][j + second_half];
			}
		}
		for (int i = 99; i<=100; i++) {
			for (int j = second_half - 1; j >= 0; j--) {
				if (i == 99)
					last_dow[98][second_half - 1 - j] = next_dow[i][j];
				if (i == 100)
					last_dow[97][second_half - 1 - j] = next_dow[i][j];
			}
		}
		copy(&last_dow[0][0], &last_dow[100][101], &dow[0][0]);
}		

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k; //100,0에서 시작
	for (int i = 0; i < n; i++) {
		cin >> dow[100][i];
	}
	int cnt = 0;
	int maxx, minn;
	while (1) {
		maxx = -1;
		minn = 1000000;
		for (int j = 0; j < 101; j++) {
			if (dow[100][j] == 0)
				continue;
			if (dow[100][j] < minn)
				minn = dow[100][j];
			if (dow[100][j] > maxx)
				maxx = dow[100][j];
		}
		if (maxx - minn <= k)
			break;
		//cout << maxx << ' ' << minn << '\n';
		step1();
		step2();
		step3();
		step4();
		step3();
		cnt++;
	}
	cout << cnt;


}