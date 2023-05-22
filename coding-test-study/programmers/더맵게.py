import heapq
def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    
    while True:
        min1 = heapq.heappop(scoville)

        if min1 >= K:
            return answer
        if len(scoville) == 0:
            return -1

        min2 = heapq.heappop(scoville)
        newScoville = min1 + (min2*2)
        heapq.heappush(scoville, newScoville)
        answer += 1

    
