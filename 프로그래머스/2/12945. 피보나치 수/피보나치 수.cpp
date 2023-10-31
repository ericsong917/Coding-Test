#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1; // == f(n-1) % 1234567
    int before = 0; // == f(n-2) % 1234567
    int tmp;

    for (int i = 2; i <= n; i++) {
        tmp = answer;
        answer = (answer % 1234567 + before % 1234567) % 1234567; // == f(n) % 1234567
        before = tmp;
    }
    return answer;
}