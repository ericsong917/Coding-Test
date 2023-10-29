def solution(r1, r2):
    cnt = 0
    # 그래프의 한 사분면만 고려
    for i in range(1, r2):
        y1s = (r1**2 - i**2) if r1 > i else 0
        y1 = int(y1s**0.5)
        y2 = int((r2**2 - i**2)**0.5)
        # x 좌표값에 대한 점의 개수
        cnt += y2 - y1 + (1 if y1 ** 2 == y1s else 0)
    # x 좌표값 = r2 일 때
    cnt += 1
    return cnt * 4
    
# 입출력 예시
print(solution(2, 3))