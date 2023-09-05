from heapq import heapify
from heapq import heappop
from heapq import heappush

def solution(scoville, K):
    ans=0
    heapify(scoville)
    while(scoville[0] < K):
        if(len(scoville) <=1):
            return -1
        else :
            first = heappop(scoville)
            second = heappop(scoville)
            ans+=1
            heappush(scoville,first + second*2)
    return ans
    
    
    