import heapq
import sys
MAXINT = sys.maxsize

V, E = map(int, input().split())
K = int(input())
graph = [[] for _ in range(V + 1)]
dist = [MAXINT] * (V + 1)
priority_queue = []
def dijkstra(k):
    dist[k] = 0
    heapq.heappush(priority_queue, (0, k))
    while priority_queue:
        cur_dist, cur = heapq.heappop(priority_queue)

        if dist[cur] < cur_dist:
            continue
        for next_dist, next in graph[cur]:
            if dist[next] > next_dist + cur_dist:
                dist[next] = next_dist + cur_dist
                heapq.heappush(priority_queue, (dist[next], next))

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append([w, v])

dijkstra(K)

for j in range(1, V + 1):
    if dist[j] == MAXINT:
        print("INF")
    else:
        print(dist[j])