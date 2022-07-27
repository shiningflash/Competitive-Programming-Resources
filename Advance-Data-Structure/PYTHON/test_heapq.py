import heapq

a = [1, 5, 2, 1000, 0, 12]
heapq._heapify_max(a)
print(a)
heapq.heappush(a, 8)
heapq._heapify_max(a)
print(a)
print(heapq.heappop(a))
heapq._heapify_max(a)
print(heapq.heappop(a))
heapq._heapify_max(a)
print(heapq.heappop(a))
heapq._heapify_max(a)
print(heapq.heappop(a))
