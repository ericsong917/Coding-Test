#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 점수를 분류한 구조체
struct Score{
    int work;
    int friends;
};

// 근무 태도 기준 오름차순
bool workOrder(Score a, Score b){
    return a.work < b.work;
}

// 총합 기준 내림차순 정렬 기준
bool sumOrder(Score a, Score b){
    int s1 = a.work + a.friends;
    int s2 = b.work + b.friends;
    return s1 > s2;
}

int solution(vector<vector<int>> scores) {
    vector<Score> list;
    Score target;
    for(int i = 0; i < scores.size(); i++){
        // 타겟이라는 변수에 담음
        if(i == 0) target = {scores[i][0],scores[i][1]};
        
        Score tmp = {scores[i][0],scores[i][1]};
        list.push_back(tmp);
    }
    // 근무 태도 기준으로 오름차순 정렬
    sort(list.begin(),list.end(),workOrder);
    
    for(int i = 0; i < list.size()-1; i++){
        bool del = false; // 삭제됐는지 체크
        for(int j = i+1; j < list.size(); j++){
            // 근무 태도가 같다면 둘다 낮은게 아니니까 패스
            if(list[i].work == list[j].work) continue;
            // 동료 평가가 오른쪽 인덱스에 있는 것보다 낮은 경우
            if(list[i].friends < list[j].friends){
                list.erase(list.begin()+i); // 삭제
                del = true;
                break;
            }
        }
        if(del) i--; // 삭제됐을 경우 인덱스를 정상적으로 하기 위해
    }
    
    // 등수를 매기기 위해 총합 기준으로 내림차순 정렬
    sort(list.begin(),list.end(),sumOrder);
    
    int rank = 1; // 등수
    int tmp = 0; // 동일 등수 뒤에 한번에 등수 오를때
    bool success = false; // 타깃이 list에 들어있는지 확인
    int cnt = 0; // 현재 총합 점수
    
    
    for(int i = 0; i < list.size(); i++){
        int sum = list[i].work + list[i].friends;
        
        // 타깃을 찾았을 때
        if(target.work == list[i].work 
           && target.friends == list[i].friends) {
            if(cnt != sum) rank += tmp; // 앞에 총합 점수와 같지 않을 경우 밀린 만큼 더해짐
            success = true; // 타깃 찾았다고 체크
            break;
        }
        if(cnt == sum) tmp++; // 총합 점수가 같을 경우 rank는 안더함
        else {
            // 총합 점수가 다를 경우 tmp에 담아뒀던 걸 더함
            rank += tmp+1;
            tmp = 0;
        }
        cnt = sum; // 총합 점수 동기화
    }
    int answer = rank;
    if(!success) answer = -1; // 실패하면 -1 반환
    return answer;
}